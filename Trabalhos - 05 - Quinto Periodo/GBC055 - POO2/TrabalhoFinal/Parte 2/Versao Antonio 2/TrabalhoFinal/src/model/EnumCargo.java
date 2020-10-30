package model;

public enum EnumCargo {
    Gerente("Gerente"),
    Faxineiro("Faxineiro"),
    Recepcionista("Recepcionista"),
    Gerente_Restaurante("Gerente Restaurante"),
    Garcom("Garçom")
    ;
    
    private final String text;
    
    EnumCargo(final String text)
    {
        this.text = text;
    }
      
    @Override
    public String toString() {
        return text;
    }
    
}
