//data types - :Atom, "String", 'char', [linked list] (or normal List), {Tuple}, [Keyword : list] key is atom, %{Map}, 

atom = :"i am a atom data type" 
atoms = :atoms
name = "vpra"

welcome = "hello " <> name

?a

?b


// these << >> are used to represent stings in binary for ex: i(sting_name)
<<begin, rest::binary>> = name
head

begin == ?v

<<begin::binary-size(2), resty::binary>> = name
begin

chars = 'vpra'
"hello " ++ chars

is_list(char)

pid = self()
pid

list = ["a", "b", "c", "d"]

Enum.at(list, 0)

//Enum. and tab for every in-bulit function
//h for help for ex: h Enum.at

[h | r] = list

{:heelo, status} = {:heelo, 200}
:heelo
status

data = [a: 1, b: 2]

map = %{a: 1, b: 2, c: 3}

%{b: second} = map
second
map.a

map2 = %{"ab" => 12, "cd" => 34}

map2  = %{map2 | "c" => 4}

u1 = %User{username: "vpra", email: "vpra@heelo.io", age: 20}
u1
u1.age

u1 = %{u1 | age: 21}

list = [1, 2, 3]

case Enum.at(list, 2) do
    1 -> "this is one"
    2 -> "this is two"
    3 -> "this is three"
    _ -> "default case"
end

case post1 do
    %{author: "vpra"} -> "gpt a post from vpra"
    _ -> "got a post from #{post1.author}"
end

cond do
    post1.author == "vpra" -> "edited by vpra"
    true -> "everything"
end

