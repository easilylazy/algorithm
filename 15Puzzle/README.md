# [15Puzzle](https://github.com/easilylazy/algorithm/tree/main/15Puzzle)
对8/15(++)数码问题的c++实现，并可方便进行不同搜索函数的应用



## Quick Start
1. `git clone https://github.com/easilylazy/algorithm.git`
2. `cd algorithm/15Puzzle`
3. `mkdir build`
4. `cd build`
5. `cmake ..`
6. `make`
7. `./board.exe [size] [steps]`
## example
`./board.exe 3 35`
``` bash
-------TARGET--------
    1     2     3
    4     5     6
    7     8     0

after shuffle 35 steps
-------START--------
    1     4     2
    7     8     3
    5     0     6

after 71 steps, achieve target
after 31 steps, achieve target
after 1199 steps, achieve target
after 119 steps, achieve target
BFS after 52650 steps,  achieve target
```


