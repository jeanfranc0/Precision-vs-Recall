# Compute-the-average-Precision-Recall-curves

![](img/diagrama.png)

In this work, the aim is to answer [7th assignment](http://www.ic.unicamp.br/~rtorres/mo805A_19s1/07-assignment.pdf)  of the discipline [MO805A - Topics on Information Retrieval](http://www.ic.unicamp.br/~rtorres/mo805A_19s1/index.html)

This is divided into three parts: 
* Convert files from .gif to .pgm
* Feature extraction 
* Compute the average Precision × Recall

## Convert files

Currently, there is a code that extracts different characteristics. However, this code only accepts images in .pgm format. By entering the `MO445-descriptors/` folder you can see detail of the  [readme.txt](https://github.com/jeanfranc0/Precision-vs-Recall/blob/master/MO445-descriptors/readme.txt).
To convert the .gif files to .pgm the following steps are considered:
* First, download the Mpeg-7 database in [7th assignment](http://www.ic.unicamp.br/~rtorres/mo805A_19s1/07-assignment.pdf) and rename it as `mpeg7/`
* Second, extract the files in MO445-descriptors.tar.gz.
* Third, create a folder to store the images .pgm. For example: `mpeg7_output_git_to_pgm/` 
* Fourth, Open file `Convert_git_to_pgm.ipynb` and execute each cell sequentially. The output will be the following:

![Recursive outpainting](img/gif_to_pgm.jpg)

## Feature extraction

Some modifications were made to the [readme.txt](https://github.com/jeanfranc0/Precision-vs-Recall/blob/master/MO445-descriptors/readme.txt) code. Specifically, to read the files in the folder.

Follow the steps:

* First, go to the folder `MO445-descriptors` and execute the Makefile. For example:`make`

* Second, go to the folder examples (`MO445-descriptors/examples`), which contains one
example file "test.c". Move folder `mpeg7_output_git_to_pgm/` to this ubication (`examples/mpeg7_output_git_to_pgm/`).

* Third, Execute the Makefile. It will generate a executable file "test". For example:`make`. Then create two folders `mpeg7_Saliences` and `mpeg7_Fractal`.

* Fourth, Run `./test`. This is configured by default to execute "Extracting Multiscale Fractal Dimension". This will generate feature vectors in .txt format 

* Fifth, Replace code lines 26 through 36 with the following code fragment:
  ```
  >> fprintf(stderr,"\nExtracting Segment Saliences ... ");
  >> fvMS2 = SS_ExtractionAlgorithm(img1);
	>> //fprintf(stderr,"\nExtracting Multiscale Fractal Dimension ... ");
	>> //fvMS2 = MS_ExtractionAlgorithm(img1);
	>> ptr = strtok(de->d_name, delim);
	>> strcpy(path , "mpeg7_output_git_to_pgm/"); 
	>> strcat(path_output, ptr);
	>> strcat(path_output, ".txt");
	>> WriteFeatureVector1D(fvMS2, path_output);
	>> strcpy(path_output , "mpeg7_pgm_output_Segment/"); 
	>> strcpy(path , "mpeg7_output_git_to_pgm/"); 
	>> //strcpy(path_output , "mpeg7_Fractal/");
  >> //fprintf(stderr,"\nExtracting Segment Saliences ... ");
  ```
* Sixth, Change `char path_output[50] = "mpeg7_Fractal/"` code line 16 to `char path_output[50] = "mpeg7_Saliences/"`. Execute the Makefile. It will generate a executable file "test".

* Fourth, Run `./test`. This is configured by default to execute "Extracting Segment Salience". This will generate feature vectors in .txt format 

## Compute the average Precision × Recall

If you do not want to perform the previous processes, feature vectors are inside the `example` folder. Finally, run `example/Precision_x_Recall.ipynb` ,you simply need to run the cells sequentially and you will get the Precision × Recall (see figure)

![Recursive outpainting](img/Precision_Recall.png)

## Requirements
* numpy '1.16.2'
* scipy '1.2.1'
* matplotlib: '3.0.2'
* PIL '1.1.7'
