defmodule User do
    defstruct username: "", email: "", age: nil
end

defmodule Post do
    defstruct(
        id: nil,
        title: "",
        description: "",
        author: ""
    )
end

