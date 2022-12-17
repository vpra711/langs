package own

import (
	"strconv"
)

func IntToStr(x []int) []string{

	var result []string

	for _, val := range x{

		result = append(result, strconv.Itoa(val))
	}

	return result
}

type Player struct{
	name string
	score int
	level int
}

//functions implemetation to player
func (p *Player) SetName(name string){

	p.name = name
}

func (p *Player) SetScore(score int){

	p.score = score
}
func (p *Player) SetLevel(level int){

	p.level = level
}

func (p *Player) GetName() string{

	return p.name
}

func (p *Player) GetScore() int{

	return p.score
}

func (p *Player) GetLevel() int{

	return p.level
}

func UpperCase(){
	print("this is public")
}

func lowerCase(){
	print("this is private")
}