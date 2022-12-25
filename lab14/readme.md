Now we need to go through an array. 
Array can be 1000x1000 size so we would have a stack overflow using the common way of arrays(4 bytes * 1000 * 1000 = 4MB, in my Windows stack is only 1MB).
So, we must use malloc().
