import java.util.ArrayList;

class Ex3
{
    public static void main(String[] args) {
        //Pesos:  56, 59, 80, 64, 75, 17
        //Valores: 50, 50, 64, 46, 50, 05

        Item a = new Item(56, 50);
        Item b = new Item(59, 50);
        Item c = new Item(80, 64);
        Item d = new Item(64, 46);
        Item e = new Item(75, 50);
        Item f = new Item(17, 05);
        ArrayList<Item> items = new ArrayList<>();
        items.add(a);
        items.add(b);
        items.add(c);
        items.add(d);
        items.add(e);
        items.add(f);
        Knapsack k = new Knapsack(items, 190);
        System.out.println(k.run());
    }
}

class Item
{
    public int peso;
    public int valor;

    public Item(int peso, int valor)
    {
        this.peso = peso;
        this.valor = valor;
    }

    @Override
    public String toString() {
        return String.format("Peso: %d Valor: %d\n", this.peso, this.valor);
    }

}

class Solucao
{
    public ArrayList<Item> items;
    public int valor = 0;
    public int peso = 0;

    public Solucao(ArrayList<Item> items)
    {
        this.items = items;
        for (Item item : items) {
            this.valor += item.valor;
            this.peso += item.peso;
        }
    }

    public void add(Item i)
    {
        this.items.add(i);
        this.valor += i.valor;
        this.peso += i.peso;
    }
    public void remove(Item i)
    {
        boolean b = this.items.remove(i);
        if (b) 
        {
            this.valor -= i.valor;
            this.peso -= i.peso;
        }
    }
    public Solucao copy()
    {
        return new Solucao(new ArrayList<>(this.items));
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Item item : items) {
            sb.append(item.toString());
        }
        sb.append(String.format("Peso da solucao %d", this.peso));
        return sb.toString();
    }

}

class Knapsack
{
    private ArrayList<Item> items;
    private int capacidade;

    public Knapsack(ArrayList<Item> valores, int capacidade)
    {
        this.items = valores;
        this.capacidade = capacidade;
    }

    public Solucao run() {

        return buscaLargura(new Solucao(new ArrayList<>()));
    }
    public Solucao buscaProfundidade(Solucao parcial)
    {
        Solucao best = new Solucao(new ArrayList<>());
        boolean canGoDeeper = false;
        for (Item item : this.items) {
            if (parcial.items.contains(item)) continue;     // Se já na mochila ignora
            if (parcial.peso + item.peso > this.capacidade) continue; // Se não cabe ignora
            canGoDeeper = true;
            Solucao new_parcial = parcial.copy();
            new_parcial.add(item);
            new_parcial = buscaProfundidade(new_parcial);
            if (new_parcial.valor > parcial.valor) best = new_parcial;
        }
    
        return canGoDeeper?best:parcial;
    }

    public Solucao buscaLargura(Solucao parcial)
    {
        Solucao best = new Solucao(new ArrayList<>());
        ArrayList<Solucao> atuais = new ArrayList<>();
        boolean canGoDeeper = false;
        for (Item item : this.items) {
            if (parcial.items.contains(item)) continue;     // Se já na mochila ignora
            if (parcial.peso + item.peso > this.capacidade) continue; // Se não cabe ignora
            canGoDeeper = true;
            Solucao new_parcial = parcial.copy();
            new_parcial.add(item);
            atuais.add(new_parcial);
        }
        if (canGoDeeper)
        {
            for (Solucao solucao : atuais) {
                Solucao volta = buscaLargura(solucao);
                if (volta.valor > best.valor) best = volta;
            }
        }
        else return parcial;
        return best;
    }
}