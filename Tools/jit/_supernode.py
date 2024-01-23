import dataclasses
import functools

@dataclasses.dataclass
class SuperNode:
    ops: list[str]
    index: int = -1

    @functools.cached_property
    def name(self):
        return 'plus'.join(self.ops)
    
    @functools.cached_property
    def length(self):
        return len(self.ops)
    
    def pop_front(self):
        return self.__class__(ops=self.ops[1:])
    

