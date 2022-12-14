package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"reflect"
	"strconv"
	"strings"
	"time"
	"unicode/utf8"
)

var print = fmt.Println //alias

func main() {

	//io_ops()
	//datatype_cast()
	//str_ops()
	//runes()
	//times()
	//controlflow()
	//guessgame()
	//arrays()
	//print(add(2, 3))
	//print(multiplereturns(6))
	//pointers()
	file_ops()

}

func io_ops() {

	fmt.Println("heelo wolrd!")
	var a = 2
	b := 3
	var c int
	c = 4

	print(a, b, c)

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

func str_ops(){

	s1 := "heelo"
	s2 := strings.NewReplacer("h", "heelo")

	print(s1, s2)
}

func runes(){

	str := "heelo"

	char := utf8.RuneCountInString(str)

	for i, rval := range str{
		print(i, rval, char)
	}
}

func times(){

	timeNow := time.Now()

	year, month, day := timeNow.Date()

	print(year, month, day, timeNow.Second())
}

func controlflow(){

	// only for and switch exists

	for i := 0; i < 20; i++ {
		print(i)
	}

	value := 3

	switch value{
	case 1: print("one")
			break
	case 2: print("two")
			break
	case 3: print("three")
			break
	default: print("default")
	}
}


func guessgame(){

	unixTime := time.Now().Nanosecond()
	rand.Seed(int64(unixTime))
	random := rand.Intn(15)

	reader := bufio.NewReader(os.Stdin)

	var input string
	var err error
	var inputTemp int

	for {
		input, err = reader.ReadString('\n')

		if(err != nil){

			print("error in input")
		}

		input = strings.TrimSpace(input)
		inputTemp, err = strconv.Atoi(input)

		if(err != nil){

			print("error in converting")
		}

		if(inputTemp > random){

			print("entered value is high")

		} else if(inputTemp < random){

			print("entered value is low")

		} else{

			print("entered value is correct")
			break

		}
	}
}

func arrays(){

	var arr [5]int

	print()
	for i := range arr{
		arr[i] = i + 10
	}

	print()
	for i, val := range arr{
		print(i, val)
	}

	print()
	arr2 := []int{6, 7, 8, 9, 12}

	for i, val := range arr2{
		print(i, val)
	}

	arr3 := [][]int{ {1, 2, 3}, {4, 5, 6} }

	print("\nmodern for loop")
	for _, val := range arr3{
		for j, val2 := range val{
			print(j, val2)
		}
	}

	print("\nc-like for loop")
	for i := 0; i < 2; i++{
		for j := 0; j < 3; j++{
			print(arr3[i][j])
		}
	}

	str := "heelo"

	runeArray := []rune(str)

	for _, val := range runeArray{
		print(val)
	}

	print(arrays1(arr2...))

}

func arrays1(arr ...int) int{

	sum := 0

	for _, val := range arr{
		sum += val
	}

	return sum
}

func add(x int, y int) int{

	return x + y
}

func multiplereturns(x int) (int, int){

	return x, x + 1
}

func pointers(){

	var ptr *int

	val := 4;
	ptr = &val
	*ptr = 20

	print(val)
}

func file_ops(){

	file, err := os.Create("heelo.txt")

	if(err != nil){
		log.Fatal(err)
	}

	file.WriteString("heelo file")
	file.Close()
	file, err = os.Open("heelo.txt")

	if(err != nil){
		log.Fatal(err)
	}

	scan := bufio.NewScanner(file)

	for scan.Scan(){
		print(scan.Text())
	}

	str := os.Environ()

	for _, val := range str{
		print(val)
	}

}

