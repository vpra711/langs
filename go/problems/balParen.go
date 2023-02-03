package main

import(
	"fmt"
)

var set map[string]int = make(map[string]int)

func main(){
	lenParen := 5
	lenParen += lenParen
	generateParenthesis("()", lenParen)

	for k := range set {
		fmt.Println(k)
	}

}

func generateParenthesis(x string, len int){

	if(len == 0){
		set[x] = len
	}

	if(len > 0){
		generateParenthesis(x + "()", len - 2)
		generateParenthesis("(" + x + ")", len - 2)
		generateParenthesis("()" + x, len - 2)
	}

}