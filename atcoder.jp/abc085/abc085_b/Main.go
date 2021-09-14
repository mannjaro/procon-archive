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
	a := make(map[int]int,0)
	for i := 0; i < N; i++ {
		a[nextInt()]++
	}
	fmt.Println(len(a))
}
