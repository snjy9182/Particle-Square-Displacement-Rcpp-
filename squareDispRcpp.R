## squareDispRcpp.R (with squareDispRcpp.cpp dependency)
##
## Wu Lab, Johns Hopkins University
## (Referenced squareDisp.R algorithm from Sheng Liu)
##
## Author: Sun Jay Yoo
## Date: May 17, 2017


#GCC GNU Fortran compiler required
#TERMINAL COMMANDS:
# $ curl -O http://r.research.att.com/libs/gfortran-4.8.2-darwin13.tar.bz2
# $ sudo tar fvxz gfortran-4.8.2-darwin13.tar.bz2 -C /

#Rcpp Armadillo required
#R COMMANDS:
# install.packages("RcppArmadillo")

#Load required packages
library(Rcpp)
library(RcppArmadillo)

#To load sample track data
library(smt)
folder=system.file("extdata","SWR1",package="smt")
trackll=readDiatrack(folder)
track = trackll[[1]][[3]]

#convert given track to matrix type
track = data.matrix(track)

#Compile source C++ file, enter file path of file
sourceCpp("/Users/sunjayyoo/Dropbox/Work/Particle\ Square\ Displacement/squareDispRcpp.cpp")

#run squareDispRcpp.cpp 
#(pass in an additional argument to change dt from the default of 1)
#(pass in an another additional argument to change resolution from the default of 0.107)
squareDispRcpp(track)
squareDispRcpp(track, 2)
squareDispRcpp(track, 8)
squareDispRcpp(track, 9)

