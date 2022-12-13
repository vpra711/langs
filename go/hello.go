package main

import (
	"bufio"
	"math/rand"
	"fmt"
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

