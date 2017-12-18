#!/usr/bin/env python
"""
exctraction of eye coordinates from the colour-feret xml format to the CSU 
software input format , that is:
<filename> <l_eye_x> <l_eye_y> <r_eye_x> <r_eye_y> <nose_x> <nose_y> <mouth_x> <mouth_y> 

Giuseppe Passino, 2010
"""

import sys;
import xml.parsers.expat;

class Point(object):
	def __init__(self, x = 0, y = 0):
		self.x = x;
		self.y = y;

class Coord(object):
	poses = ("fa fb");
	
	def __init__(self, l_eye, r_eye, nose, mouth, pose, filename):
		self.l_eye = l_eye;
		self.r_eye = r_eye;
		self.nose  = nose ;
		self.mouth = mouth;
		self.pose = pose;
		self.filename = filename;
	
	def line(self):
		return "%s %d %d %d %d %d %d %d %d" % (self.filename, self.l_eye.x, self.l_eye.y, self.r_eye.x, self.r_eye.y, self.nose.x, self.nose.y, self.mouth.x, self.mouth.y) ;
	
	@staticmethod
	def build(l_eye, r_eye, nose, mouth, pose, filename):
		if l_eye == None:
			return None;
		elif not r_eye:
			return None;
		elif not nose:
			return None;
		elif not mouth: 
			return None;
		elif not pose:
			return None;
		elif not filename :
			return None;
		elif pose not in Coord.poses :
			return None;
		return Coord(l_eye, r_eye, nose, mouth, pose, filename);
	

def extractFilename(relative):
	start = relative.rfind('/');
	res = relative[start+1:];
	end = res.find('.');
	if end != -1:
		res = res[0:end];
	return res;


# globals
l_eye = None;
r_eye = None;
nose  = None;
mouth = None;
pose  = None;
ifile = None;
coords = [];

def parseFile(filename) :
	
	def startElementHandler(name, args) : 
		global l_eye, r_eye, nose, mouth, pose, ifile;
		if   name == "Recording":
			l_eye = None;
			r_eye = None;
			nose  = None;
			mouth = None;
			pose  = None;
			ifile = None;
		elif name == "LeftEye":
			l_eye = Point(int(args['x']), int(args['y']));
		elif name == "RightEye":
			r_eye =  Point(int(args['x']), int(args['y']));
		elif name == "Nose":
			nose  = Point(int(args['x']), int(args['y']));
		elif name == "Mouth":
			mouth = Point(int(args['x']), int(args['y']));
		elif name == "Pose":
			pose  = args['name'];
		elif name == "URL":
			ifile = extractFilename(args['relative']);
	
	
	def endElementHandler(name) : 
		global l_eye, r_eye, nose, mouth, pose, ifile, coords;
		if name == "Recording":
			coord = Coord.build(l_eye, r_eye, nose, mouth, pose, ifile);
			if(coord != None) :
				coords.append(coord);
	
	fin = open(filename, 'r');
	p = xml.parsers.expat.ParserCreate();
	p.StartElementHandler = startElementHandler;
	p.EndElementHandler = endElementHandler;
	p.ParseFile(fin);
	global coords;
	return coords;
		

def writeFile(filename, coords) : 
	fout = open(filename, 'w');
	for coord in coords:
		fout.write(coord.line()+'\n');

def main(args) : 
	if(len(args) not in (3,4)) : 
		print "usage: " + args[0]  + " <input-filename> <output-filename> [\"list of allowed poses\"=\"fa fb\"\"]";
		return 1;
	if(len(args) == 4):
		Coord.poses = args[3].split(" ");
		for pose in Coord.poses:
			pose.strip();
	coords = parseFile(args[1]);
	writeFile(args[2], coords);
	

if __name__ == '__main__' :
	main(sys.argv);



