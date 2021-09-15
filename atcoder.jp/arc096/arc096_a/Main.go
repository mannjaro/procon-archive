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
	A := nextInt()
	B := nextInt()
	C := nextInt()
	X := nextInt()
	Y := nextInt()
	minPrice := A*X + B*Y
	for c := 2; float64(c) <= math.Max(float64(X), float64(Y))*2; c += 2 {
		a := X - c/2
		b := Y - c/2
		if a < 0 {
			a = 0
		}
		if b < 0 {
			b = 0
		}
		price := a*A + b*B + c*C
		if minPrice >= price {
			minPrice = price
		}
	}
	fmt.Println(minPrice)
}
