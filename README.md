# Leader-Election

使用Chang and Roberts 算法。算法包括两个阶段：选举阶段和传递选举结果阶段。
● 在选举阶段中，每个节点都是一个候选人，向其它节点发送选举消息，消息内容是自己的ID。当一个节点收到邻居节点传递的消息后：
  ○ 如果该节点接收到的选举信息的值比自己的值大，那么它就放弃竞选，并转发接收到的信息。
  ○ 如果该节点接收到的选举信息的值比自己的值小，那么它就变为候选人，并向其它节点发送自己的选举信息。
  ○ 如果该节点接收到的选举信息的值和自己的值相同，那么它就当选为领导者，并向其它节点发送当选信息。
● 在传递选举结果阶段中，领导者向其它节点发送自己的标识符，告诉它们自己已经当选。
