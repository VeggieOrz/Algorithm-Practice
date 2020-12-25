class Solution {
    public String replaceSpace(String s) {
        String news="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' ')
                news+="%20";
            else
                news+=s.charAt(i);
        }
        return  news;
    }
}

public class MainClass {
    public static String stringToString(String input) {
        if (input == null) {
            return "null";
        }
        return Json.value(input).toString();
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            String s = stringToString(line);
            
            String ret = new Solution().replaceSpace(s);
            
            String out = (ret);
            
            System.out.print(out);
        }
    }
}
