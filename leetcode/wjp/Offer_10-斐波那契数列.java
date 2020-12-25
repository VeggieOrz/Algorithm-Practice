class Solution {
    public int fib(int n) {
        int[] list=new int[n+1];
        list[0]=0;
        if(n>=1)
            list[1]=1;
        for(int i=2;i<=n;i++)
            list[i]=(list[i-1]+list[i-2])%1000000007;
        return list[n];
    }
}

public class MainClass {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int n = Integer.parseInt(line);
            
            int ret = new Solution().fib(n);
            
            String out = String.valueOf(ret);
            
            System.out.print(out);
        }
    }
}
