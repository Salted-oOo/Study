import java.io.*;
import org.antlr.runtime.*;
import org.antlr.runtime.debug.DebugEventSocketProxy;


public class __Test__ {

    public static void main(String args[]) throws Exception {
        ExprCppTreeLexer lex = new ExprCppTreeLexer(new ANTLRFileStream("/Users/salted_fish/Desktop/Study/Project/1.Search/ANTLR/libantlr3c-3.4/output/__Test___input.txt", "UTF8"));
        CommonTokenStream tokens = new CommonTokenStream(lex);

        ExprCppTreeParser g = new ExprCppTreeParser(tokens, 49100, null);
        try {
            g.expr();
        } catch (RecognitionException e) {
            e.printStackTrace();
        }
    }
}