package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = *bufio.NewScanner(os.Stdin)

func readLine(sc bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	sc.Split(bufio.ScanWords)
	N := 3
	matrix := make([][]int, 3)
	for i := 0; i < N; i++ {
		matrix[i] = make([]int, 3)
		for j := 0; j < N; j++ {
			matrix[i][j] = nextInt()
		}
	}
	c1 := matrix[0][0] + matrix[1][1] + matrix[2][2]
	c2 := matrix[1][0] + matrix[2][1] + matrix[0][2]
	c3 := matrix[2][0] + matrix[0][1] + matrix[1][2]
	if c1 == c2 && c2 == c3 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
