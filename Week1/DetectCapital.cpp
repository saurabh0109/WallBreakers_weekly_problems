public class Solution {
    public bool DetectCapitalUse(string word) {
        
        if(word.Length == 1)
            return true;
        
        bool firstChar = Char.IsUpper(word[0]);
        bool SecondChar = Char.IsUpper(word[1]);
        
        bool CapitalUse = true;
        
        foreach( var c in word.Substring(1))
        {
            if(firstChar)
            {
                if(SecondChar)
                    CapitalUse = (CapitalUse && Char.IsUpper(c));
                else
                    CapitalUse = (CapitalUse && Char.IsLower(c));
            }
            else
                CapitalUse = (CapitalUse && Char.IsLower(c));
        }
        
        return CapitalUse;
    }
}