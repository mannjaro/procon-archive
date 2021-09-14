package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	N := nextInt()
	a := make([]int,0)
	for i := 0; i < N; i++ {
		a = append(a, nextInt())
	}
	var A, B int
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	for index, d := range a {
		if (index % 2) == 0 {
			A+= d
		} else {
			B+= d
		}
	}
	del := A - B
	if del < 0 {
		del = -del
	}
	fmt.Println(del)
}
