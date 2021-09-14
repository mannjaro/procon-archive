package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)
var sc = *bufio.NewScanner(os.Stdin)

func readLine (sc bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextInt () int {
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
	var cnt int
	for a := 0; a <= A; a++ {
		for b := 0; b <= B; b++ {
			for c := 0; c <= C; c++ {
				sum := a * 500 + b * 100 + c * 50
				if sum == X {
					cnt++
				}
			}
		}
	}
	fmt.Println(cnt)
}
