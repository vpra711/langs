package main

import (
	"bufio"
	"fmt"
	"os"
	"reflect"
	"strconv"
)

var print = fmt.Println //alias

func main() {

	fmt.Println("Heelo World")

	var a = 2
	b := 3
	var c int
	c = 4

	print(a, b, c)

	//io_ops()
	//datatype_cast()
}

func io_ops() {

	print("Now in io_ops")

	reader := bufio.NewReader(os.Stdin)

	name, err := reader.ReadString('\n')

	if err == nil	{
		print(name)
	} else {
		print("Some error occured")
	}
}

func datatype_cast() {

	print(reflect.TypeOf(25))
	print(reflect.TypeOf(2.5))
	print(reflect.TypeOf('2'))
	print(reflect.TypeOf("25"))
	print(reflect.TypeOf(true))

	a := 1
	b := float64(1)
	c := "Heelo"
	d, err := strconv.Atoi(c)

	print(a, b, c, d, err)
}


