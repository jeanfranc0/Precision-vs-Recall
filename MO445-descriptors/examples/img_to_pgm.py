#!/usr/bin/python2
import numpy as np
import argparse
from PIL import Image
import gdal

def readPGM(filename):
	try:
		inFile = open(filename)
		header = None
		size = None
		maxGray = None
		data = []

		for line in inFile:
			stripped = line.strip()
			if stripped[0] == '#': 
				continue
			elif header == None: 
				if stripped != 'P2': return None
				header = stripped
			elif size == None:
				size = map(int, stripped.split())
			elif maxGray == None:
				maxGray = int(stripped)
			else:
				for item in stripped.split():
					data.append(int(item.strip()))
		
		data = np.reshape(data, (size[1],size[0]))
		return data

	except Exception, e: 
		print e
	return None

def writePGM(image, filename):
	image = image.astype(np.int)
	try:
		outFile = open(filename, 'w')
		outFile.write("P2\n")
		nrows = image.shape[0]
		ncols = image.shape[1]
		maxval = np.max(image)
		outFile.write("%d %d\n" % (ncols, nrows))
		outFile.write("%d\n" % maxval)
		for i in range(image.shape[0]):
			#for j in range(image.shape[1]):
			#	outFile.write("%d " % image[i,j])
			#outFile.write("\n")
			row_content_list = image[i,:].tolist()
			row_content_list = [str(item) for item in  row_content_list] 
			row_content_str = " ".join(row_content_list) + "\n"
			outFile.write(row_content_str)

		outFile.close()

	except Exception, e:
		print e

	return None

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument("fileImage", type=str, help="Image filename (tif)")
	parser.add_argument("-o", "--output", type=str, help="Output convert tif or npy filename to pgm")
	args = parser.parse_args()

	fileImage = args.fileImage
	output = args.output
	image = None

	if fileImage.endswith(".npy"):
		image = np.load(fileImage)
	else:
		image = gdal.Open(fileImage).ReadAsArray()
	
	print image.shape

	writePGM(image, output)
		

if __name__ == '__main__':
	main()