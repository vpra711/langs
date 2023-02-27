struct human
    name::String
    id::Int
end

function fun(a::String, b::Int)
    return human(a, b)
    
end

a = fun("vpra", 5)

println(a.id)
println(a.name)