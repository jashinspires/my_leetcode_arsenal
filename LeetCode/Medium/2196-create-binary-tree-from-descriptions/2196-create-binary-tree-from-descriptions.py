class Solution:
    def createBinaryTree(self, descriptions: list[list[int]]) -> Optional[TreeNode]:
        node_map = {}
        child_nodes = set()

        for parent, child, is_left in descriptions:
            if parent not in node_map:
                node_map[parent] = TreeNode(parent)
            if child not in node_map:
                node_map[child] = TreeNode(child)

            if is_left:
                node_map[parent].left = node_map[child]
            else:
                node_map[parent].right = node_map[child]

            child_nodes.add(child)

        for root_candidate in node_map:
            if root_candidate not in child_nodes:
                return node_map[root_candidate]
