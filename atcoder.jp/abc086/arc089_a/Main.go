package main

import (
	"bufio"
	"fmt"
	"math"
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
	N := nextInt()
	x := make([]int, 110000)
	y := make([]int, 110000)
	t := make([]int, 110000)
	for i := 0; i < N; i++ {
		t[i+1] = nextInt()
		x[i+1] = nextInt()
		y[i+1] = nextInt()
	}
	for i := 0; i < N; i++ {
		dt := t[i+1] - t[i]
		dist := int(math.Abs(float64(x[i+1]-x[i]))) + int(math.Abs(float64(y[i+1]-y[i])))
		if dt < dist {
			fmt.Println("No")
			return
		}
		if (dist % 2) != (dt % 2) {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
	return
}
