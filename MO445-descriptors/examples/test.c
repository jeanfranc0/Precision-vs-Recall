#include <stdio.h>
#include "MO445.h"
#include <dirent.h> 
#include <string.h>

int main(int argc,char **argv){
	fprintf(stderr,"\nInstructions: ");
	fprintf(stderr,"\nFor the shape descriptors (Moments Invariant, Fourier Descriptor, BAS Descriptor abd Tensor Scale Descriptor) the image \nneeds to be in binary format (0 - background 1 - object)\n");
	Image *img1 = NULL;
	FeatureVector1D	*fvMS2 = NULL;
	struct dirent *de; 
    char path[50] = "mpeg7_output_git_to_pgm/";
	DIR *dr = opendir(path);
	char delim[] = ".";
	char *ptr;
	char path_output[50] = "mpeg7_Fractal/";
	
	while((de = readdir(dr)) != NULL) {
		if((strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0  )){
			fprintf(stderr, "%s\n", "entr/");
		}else{
			strcat(path, de->d_name);
			fprintf(stderr, "%s\n", path);
			img1 = ReadImage(path);
			//fprintf(stderr,"\nExtracting Segment Saliences ... ");
			 //fvMS2 = SS_ExtractionAlgorithm(img1);
			fprintf(stderr,"\nExtracting Multiscale Fractal Dimension ... ");
			fvMS2 = MS_ExtractionAlgorithm(img1);
			ptr = strtok(de->d_name, delim);
			strcpy(path , "mpeg7_output_git_to_pgm/"); 
			strcat(path_output, ptr);
			strcat(path_output, ".txt");
			WriteFeatureVector1D(fvMS2, path_output);
			//strcpy(path_output , "mpeg7_pgm_output_Segment/"); 
			strcpy(path , "mpeg7_output_git_to_pgm/"); 
			strcpy(path_output , "mpeg7_Fractal/");
		}
	}
	closedir (dr);
	DestroyImage(&img1);
	DestroyFeatureVector1D(&fvMS2);
	fprintf(stderr,"\n");

	return 0;
}