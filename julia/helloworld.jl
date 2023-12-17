import Base.+

struct human
    name::String
    id::Int32
end

function fun(a::String, b::Int)
    return human(a, b) 
end

function +(first::String, second::String)
    return join(first, second)
end

function +(first::human, second::human)
    name::String = first.name + second.name
    id::Int32 = first.id + second.id
    return human(name, id)
end

a = human("vpra", 5)
b = human("2", 10)

c = a + b

println(c)

    