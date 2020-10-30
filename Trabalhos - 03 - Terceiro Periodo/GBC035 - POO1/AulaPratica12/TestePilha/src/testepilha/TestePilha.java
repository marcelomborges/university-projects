package testepilha;

public class TestePilha {

    Pilha p = new Pilha(3);

    public static void main(String args[]) {
        try {
            new TestePilha();
        } catch (Exception e) {
            System.out.println("Erro no main!");
        } finally {
            System.out.println("finally");
        }
    }
    
    public TestePilha() throws PilhaExcecao {
        try {
            a();
        } catch (PilhaExcecao e) {
            System.out.println("Erro de pilha!");
        }
    }
    
    
    /*
    public TestePilha() throws PilhaExcecao {
        try {
            b();
        } catch (PilhaCheiaExcecao e) {
            System.out.println("Erro de pilha cheia!");
        } catch (PilhaVaziaExcecao e) {
            System.out.println("Erro de pilha vazia");
        }
    }
    */

    /*
    public TestePilha() throws PilhaExcecao {
        c();
    }
    */
    
    void a() throws PilhaExcecao {
        p.push(1);
        p.push(2);
        for (int i = 0; i <= 3; i++) {
            System.out.println(" " + p.pop());
        }
    }

    void b() throws PilhaExcecao {
        p.push(1);
        p.push(2);
        p.push(3);
        p.push(4);
        for (int i = 0; i <= 4; i++) {
            System.out.println(" " + p.pop());
        }
    }

    void c() throws PilhaExcecao {
        p.push(p.top());
        System.out.println("Fim de C");
    }
}

class Pilha {

    int pilha[];
    int top;

    Pilha(int n) {
        pilha = new int[n];
        top = -1;
    }

    int top() throws PilhaVaziaExcecao {
        if (vazia()) {
            throw new PilhaVaziaExcecao();
        }
        return pilha[top];
    }

    boolean vazia() {
        return top == -1;
    }

    boolean cheia() {
        return top == pilha.length - 1;
    }

    void push(int x) throws PilhaCheiaExcecao {
        if (cheia()) {
            throw new PilhaCheiaExcecao();
        }
        pilha[++top] = x;
    }

    int pop() throws PilhaVaziaExcecao {
        if (vazia()) {
            throw new PilhaVaziaExcecao();
        }
        return pilha[top--];
    }
}

class PilhaExcecao extends Exception {
}

class PilhaVaziaExcecao extends PilhaExcecao {
}

class PilhaCheiaExcecao extends PilhaExcecao {
}
