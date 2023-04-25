#include "String.h"

String::String() {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */
}

String::String(char *str) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    // str is a null terminated C string.
    // (e.g. ['h','e','l','l','o','\0'])

    char *temp = str;

    while (*temp != '\0') {
        this->characters.insertAtTheEnd(*temp);
        temp++;
    }
}

int String::getLength() const {
    /* TODO */
    
    int a=this->characters.getSize();
    
    return a;
}

bool String::isEmpty() const {
    /* TODO */
    return this->characters.isEmpty();
    
}

void String::appendCharacter(char character) {
    /* TODO */
     this->characters.insertAtTheEnd(character);
}

void String::insertCharacter(char character, int pos) {
    /* TODO */
    Node<char> *node=this->characters.getNodeAtIndex(pos);
    if(node==NULL) {this->characters.insertAtTheEnd(character);
        return;
    }
    this->characters.insertBeforeGivenNode(character,node);
}

void String::eraseCharacters(int pos, int len) {
    /* TODO */
    int i;
    for(i=0;i<len;i++){
        Node<char> *node=this->characters.getNodeAtIndex(pos);
        this->characters.deleteNode(node);
    }
}


void String::eraseAllCharacters() {
    /* TODO */
    this->characters.deleteAllNodes();
}

String String::substring(int pos, int len) {
    /* TODO */
    int i,a=0;
    char data;
    Node<char> *node=this->characters.getNodeAtIndex(pos);
    Node<char> *dummytail=this->characters.getDummyTail();
    String chars;
    for(i=0;i<len;i++){
        data=node->data;
        chars.appendCharacter(data);
        node=node->next;
        a++;
        if(node==dummytail) break;
    }
    
    if(a<len) return chars;
}

LinkedList<String> String::split(char separator) {
    /* TODO */
    String word;
    this->appendCharacter(separator);

    int l = this->characters.getSize();
  
    LinkedList<String> substr_list;
    for (int i = 0; i < l; i++){
 
        Node<char> *node =this->characters.getNodeAtIndex(i);
        if (node->data != separator)
            word.appendCharacter(node->data);
  
        else{
            
            substr_list.insertAtTheEnd(word);
            word.eraseAllCharacters();
            
        }
    }
     
     Node<char> *last=this->characters.getNodeAtIndex(l-1);
     this->characters.deleteNode(last);
    
    return substr_list;
}

bool String::isPalindrome() const {
    /* TODO */
    int len=this->characters.getSize();
    int i;
    Node<char> *node=this->characters.getActualHead();
    Node<char> *dummytail=this->characters.getDummyTail();
    LinkedList<char> chars(this->characters);
    for(i=0;i<len/2;i++){
        Node<char> *node1=chars.getNodeAtIndex(i);
        Node<char> *node2=chars.getNodeAtIndex(len-1-i);
        chars.swapNodes(node1, node2);
  
    }
    Node<char> *nodechars=chars.getActualHead();
  
    while(node!=dummytail&&node!=NULL){
        if(node->data==' '){
            node=node->next;
            continue;
        }
        if(nodechars->data==' '){
           nodechars=nodechars->next;
           continue; 
        } 
        if(node->data !=nodechars->data) return 0;
        node=node->next;
        nodechars=nodechars->next;
    }
    return 1;
}

bool String::operator<(const String &rhs) const {
    /* TODO */
    int t=this->getLength();
    int given=rhs.getLength();
    if(t<given) return 1;
    else return 0;
}

void String::print(bool verbose) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    Node<char> *node = this->characters.getActualHead();
    Node<char> *actualTailNode = this->characters.getActualTail();

    if (verbose) {
        std::cout << "[";
    }

    while (node && node->next) {
        if (verbose) {
            std::cout << "'" << node->data << "'";
            if (node != actualTailNode) {
                std::cout << ",";
            }
        } else {
            std::cout << node->data;
        }

        node = node->next;
    }

    if (verbose) {
        std::cout << "]";
    }

    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    Node<char> *node = string.characters.getActualHead();

    while (node && node->next) {
        os << node->data;
        node = node->next;
    }

    return os;
}
