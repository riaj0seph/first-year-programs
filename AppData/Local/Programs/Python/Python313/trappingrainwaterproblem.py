
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        list2=height
#print(list)
        def calculate(list2,begin,end):
          if begin==end:
           return 0
 #102 or 21013
          else:
           sum=0
           tiny=list2[begin] if list2[begin]<list2[end] else list2[end]
           for i in range(begin+1,end):
            if list2[i]<tiny:
               sum+=tiny-list2[i]
               list2[i]=tiny #covering the area
           return sum



  
        water=0


        orderl2=sorted(list2,reverse=True)
        highests_index=list2.index(orderl2[0])

        list2scopy=list2[:]
        for value in orderl2:
            nexthighest=list2scopy.index(value)
            begin=nexthighest if highests_index>nexthighest else highests_index
            end=nexthighest if highests_index<nexthighest else highests_index
            water+=calculate(list2,begin,end)
            list2scopy[nexthighest]=-2

        return water

