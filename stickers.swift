class Solution {
	
	func stringToDict(_ string: String) -> (Dictionary<Character, Int>, Set<Character>) {
		var myDict: [Character: Int] = [:]
		var letters = Set<Character>()
		for char in string {
			if myDict[char] != nil {
				myDict[char] = myDict[char]! + 1
			} else {
				myDict[char] = 1
				letters.insert(char)
			}
		}
		
		return (myDict, letters)
	}
	
	func solve(_ stickers: [Dictionary<Character, Int>], _ setStickers: [Set<Character>], _ target: inout Dictionary<Character, Int>,
			   _ setTarget: inout Set<Character>, _ min: inout Int, _ currentDepth: Int = 0) -> Bool {
		if target.isEmpty {
			if currentDepth < min || min == -1 {
				min = currentDepth
			}
			return true
		}
		
		if currentDepth == min {
			return true
		}

		var index = -1
		for set in setStickers {
			index += 1
			let common = set.intersection(setTarget)
			if common.isEmpty {
				continue
			}
			
			let before = target
			let setbefore = setTarget
			
			for each in common {
				
				let myDict = stickers[index]
				target[each] = target[each]! - myDict[each]!
				
				if target[each]! <= 0 {
					target.removeValue(forKey: each)
					setTarget.remove(each)
				}
			}
			
			if !solve(stickers, setStickers, &target, &setTarget, &min, currentDepth + 1) && min == -1{
				return false
			}
			target = before
			setTarget = setbefore
		}
		return false
		
		
	}
	
	func minStickers(_ stickers: [String], _ target: String) -> Int {
		var min = -1
		var (newTarget, setTarget) = stringToDict(target)
		
		var newStickers = [[Character: Int]]()
		var setStickers = [Set<Character>]()
		for myString in stickers {
			let (array , set) = stringToDict(myString)
			
			newStickers.append(array)
			setStickers.append(set)
		}
		
		solve(newStickers, setStickers, &newTarget, &setTarget, &min)
		return min
	}
}


var solution = Solution()
var stickers = ["with", "example", "science"]
var target = "thehat"

print(solution.minStickers(stickers, target))

