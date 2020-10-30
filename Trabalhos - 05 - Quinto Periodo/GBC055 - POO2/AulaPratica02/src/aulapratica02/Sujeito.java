package aulapratica02;

public interface Sujeito
{
    public void registrarObservador(Observador beholder);
    public void removerObservador(Observador beholder);
    public void notificarObservadores(String valores);
}
