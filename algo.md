<!-- Printf algorithm -->

# Printf algorithm

The printf algorithm serve me to put ideas on text.  
The main idea of this algorithm is to split the problem / function in severals modules.  

## With a buffer

We're going to use a buffer for printf. The goal of the buffer is to avoid using malloc and gain some runtime.  
We had to isolate this buffer with an iterface composed of multiples functions.  
```c
	size_t _append(buffer, item):
		static size_t	i;

		buffer[i] = item;
		if (i == BUFFER_SIZE)
			_clear(buffer);
		
```
The buffer is sized with BUFFER_SIZE define.  
The buffer.append() func return the number of bytes.
If the buffer.append() func append less than the size of arg, the arg is resized. 

## With a module parser

Before adding arguments to the buffer we've