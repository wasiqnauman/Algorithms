public class LLStack<item> {
    private class Node {
        item Item;
        Node next;
    }
    private Node first = null;

    public void push(item val){
        Node oldfirst = first;
        first = new Node();
        first.Item = val;
        first.next = oldfirst;
    }
    public boolean isEmpty() {
        return first == null;
    }
    public item pop(){
        item Item = first.Item;
        first = first.next;
        return Item;
    }
    public static void main(String[] args){
        LLStack<String> stack = new LLStack<String>();
        stack.push("World");
        stack.push("Hello ");
        System.out.print(stack.pop()+stack.pop());
    }
}

