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
	N := nextInt()
	M := nextInt()
	a := make(map[int]int,0)
	for i := 0; i < M; i++ {
		a[nextInt()]++
		a[nextInt()]++
	}
	for i := 1; i <= N; i++ {
		fmt.Println(a[i])
	}
}
