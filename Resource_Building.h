#ifndef RESOURCE_BUILDING
#define RESOURCE_BUILDING

class Resource_Building : public Building {
    private:
    int Elixir_produced;

    public:
    Resource_Building(int Elixir_produced);

    int Get_Elixir_Produced() const;
    
    void Set_Elixir_Produced(int Elixir_produced);
};

#endif
