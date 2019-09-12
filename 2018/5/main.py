polymer = open('input.txt').read()
print('inital size: {}'.format(len(polymer)))

def reactPolymer(poly):
    while True:
        previous = None
        foundReaction = False
        for index,pol in enumerate(poly):
            if previous is None: #if at begining of polymer
                previous = pol
                continue
            if pol != previous and pol.lower() == previous.lower(): #if pair found
                poly = poly.replace(previous + pol,'',1)
                foundReaction = True
            else:
                previous = pol
        
        if not foundReaction: #no pairs found in input
            return poly

#--------------------PART 1--------------------#
print('final size: {}'.format(len(reactPolymer(polymer))))

#--------------------PART 2--------------------#
pairs = {}
for pol in polymer:
    if pol.lower() in pairs:
        continue
    else:
        modifiedPolymer = polymer.replace(pol.lower(), '')
        modifiedPolymer = modifiedPolymer.replace(pol.upper(), '')
        pairs[pol.lower()] = len(reactPolymer(modifiedPolymer))

#Finding pair which caused lowest polymer count
pairMinLength = len(polymer)
pair = None
for p in pairs:
    if pairs[p] < pairMinLength:
        pairMinLength = pairs[p]
        pair = p

print(pair, pairMinLength)
