> trackll[[1]][[3]]
      x     y z
1 39.88 46.11 1
2 39.31 46.96 1
3 41.94 47.86 1
4 42.95 48.65 1
5 42.66 47.91 1
6 41.32 47.89 1
7 41.66 48.10 1
8 42.13 50.90 1
9 42.69 51.34 1
> track=trackll[[1]][[3]]
> squareDisp(track)
[[1]]
      x     y z index square.disp       dx       dy
1 39.88 46.11 1     1          NA       NA       NA
2 39.31 46.96 1     2 0.011991683 -0.06099  0.09095
3 41.94 47.86 1     3 0.088465278  0.28141  0.09630
4 42.95 48.65 1     4 0.018824446  0.10807  0.08453
5 42.66 47.91 1     5 0.007232333 -0.03103 -0.07918
6 41.32 47.89 1     6 0.020562404 -0.14338 -0.00214
7 41.66 48.10 1     7 0.001828405  0.03638  0.02247
8 42.13 50.90 1     8 0.092289244  0.05029  0.29960
9 42.69 51.34 1     9 0.005806933  0.05992  0.04708

> squareDisp(track, 2)
[[1]]
      x     y z index square.disp       dx      dy
1 39.88 46.11 1     1          NA       NA      NA
3 41.94 47.86 1     3 0.083647539  0.22042 0.18725
5 42.66 47.91 1     5 0.005963784  0.07704 0.00535
7 41.66 48.10 1     7 0.011862309 -0.10700 0.02033
9 42.69 51.34 1     9 0.132333267  0.11021 0.34668

[[2]]
      x     y z index square.disp       dx       dy
2 39.31 46.96 1     2          NA       NA       NA
4 42.95 48.65 1     4  0.18439416  0.38948  0.18083
6 41.32 47.89 1     6  0.03703179 -0.17441 -0.08132
8 42.13 50.90 1     8  0.11124077  0.08667  0.32207

> squareDisp(track, 8)
[[1]]
      x     y z index square.disp      dx      dy
1 39.88 46.11 1     1          NA      NA      NA
9 42.69 51.34 1     9   0.4035658 0.30067 0.55961

[[2]]
      x     y z index square.disp dx dy
2 39.31 46.96 1     2          NA NA NA

[[3]]
      x     y z index square.disp dx dy
3 41.94 47.86 1     3          NA NA NA

[[4]]
      x     y z index square.disp dx dy
4 42.95 48.65 1     4          NA NA NA

[[5]]
      x     y z index square.disp dx dy
5 42.66 47.91 1     5          NA NA NA

[[6]]
      x     y z index square.disp dx dy
6 41.32 47.89 1     6          NA NA NA

[[7]]
      x    y z index square.disp dx dy
7 41.66 48.1 1     7          NA NA NA

[[8]]
      x    y z index square.disp dx dy
8 42.13 50.9 1     8          NA NA NA

> squareDisp(track, 9)
Error in squareDisp(track, 9) : 
track length:	9
dt:		9
Time interval (dt) greater than track length-1