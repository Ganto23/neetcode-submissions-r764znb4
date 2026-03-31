class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mydict = {}

        for string in strs:
            sortedString = str(sorted(string))
            if sortedString not in mydict:
                mydict[sortedString] = [string]
            else:
                (mydict[sortedString]).append(string)
        
        return mydict.values()
        