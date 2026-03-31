class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret_list = []
        seen_dict = {}
        num_seen = 0
        if not strs:
            return [[""]]

        for string in strs:
            if sorted(string) not in seen_dict.values():
                seen_dict[num_seen] = sorted(string)
                ret_list.append([string])
                num_seen += 1
            
            else:
                for key,value in seen_dict.items():
                    if sorted(string) == value:
                        ret_list[key].append(string)
                        break


                #key_list = list(seen_dict.keys())
                #position = key_list.index(sorted(string))
                #ret_list[position].append(string)

        return ret_list

