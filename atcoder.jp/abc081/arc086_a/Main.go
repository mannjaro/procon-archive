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
	K := nextInt()
	a := make(map[int]int,0)
	for i := 0; i < N; i++ {
		a[nextInt()]++
	}
	values := make([]int, 0)
	for _, v := range a {
		values = append(values, v)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(values)))
	sum := 0
	if len(values) <= K {
		fmt.Println(0)
		return
	}
	for _, v := range values[K:] {
		sum+= v
	}
	fmt.Println(sum)
	return
}
