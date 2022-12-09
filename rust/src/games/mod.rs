pub mod game
{
    pub struct Details
    {
        pub name: String,
        pub players: i32,
        pub difficulty_level: String
    }

    impl Details
    {
        pub fn new(name: String, players: i32, difficulty_level: String) -> Self
        {
            return Details{name, players, difficulty_level};
        }

        pub fn get_difficult(&self) -> &String
        {
            return &self.difficulty_level;
        } 

        pub fn change_difficulty(&mut self, level: &str) -> bool
        {
            self.difficulty_level = level.to_string();
            return true;
        }
    }
}