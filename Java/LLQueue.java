public class LLQueue<item> {
    private class Node{
        item Item;
        Node next;

    }
    private Node first = null;
    private Node last = null;
    public void enqueue(item Item) {

        Node oldlast = last;
        last = new Node();
        last.Item = Item;
        last.next = null;
        if(first == null)
        {
            first = last;
        }
        else
        {
            oldlast.next = last;
        }
    }
    public boolean isEmpty(){
        return first == null;
    }
    public item dequeue(){
        item Item = first.Item;
        first = first.next;
        return Item;
    }
    public static void main(String[] args){
        LLQueue<String> x = new LLQueue<>();
        x.enqueue("Hello ");
        x.enqueue("World!");
        System.out.print(x.dequeue()+x.dequeue());
    }
}
