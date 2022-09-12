fn main()
{
    println!("Heelo world");
    main1();
    main1();
}

fn main1()
{
    for elem in [2,3,4,5,65] 
    {
        main2(elem)
    }
}

fn main2(Type : elem)
{
    while elem != 65
    {
        println!("{}", elem)
    }
}