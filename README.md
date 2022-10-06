# high_performance_computing


## :file_folder: Matrix Multiple

![image](MATRIX/algo.gif)

## 🚀&nbsp; Code

```cpp
#pragma omp parallel for private(tmp, row, col, iter)
	for (row = 0; row < _N; row++) {
		for (col = 0; col < _M;col++) {
			tmp = 0.0;
			for (iter = 0; iter < colX; iter++) {
				tmp += a[row][iter] * b[iter][col];
			}
			answer[row][col] = tmp;
		}
	}
```