import dataclasses
import functools
import typing

@dataclasses.dataclass
class SuperNode:
    """Represents a sequence of UOps to be jitted together"""
    ops: list[str]
    index: int = -1
    parent: typing.Self = None
    replace = dataclasses.replace

    def __repr__(self):
        kws = [f"{key}={value!r}" for key, value in self.__dict__.items()] + [f"name={self.name}", f"length={self.length}"]
        return "{}({})".format(type(self).__name__, ", ".join(kws))

    @functools.cached_property
    def name(self):
        return 'plus'.join(self.ops)
    
    @property
    def length(self):
        return len(self.ops)
    
    def pop_front(self):
        return self.replace(ops=self.ops[1:], parent=self)
    
    def top_parent(self):
        node = self
        while node.parent:
            node = node.parent
        return node
    
    @classmethod
    def max_depth(cls, supernodes: typing.Iterable[typing.Self]):
        return max(len(node.ops) for node in supernodes)

