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
	A := nextInt()
	B := nextInt()
	var remain, sum, retval int
	for i := 1; i <= N; i++ {
		tmp := i
		sum = 0
		for tmp != 0 {
			remain = tmp % 10
			tmp = tmp / 10
			sum += remain
		}
		if A <= sum && sum <= B {
			retval += i
		}
	}
	fmt.Println(retval)
}
