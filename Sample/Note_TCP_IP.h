#pragma once
#ifndef _NOTE_TCP_IP_H_
#define _NOTE_TCP_IP_H_

/* 第一章 网络基础

	@1.7 传输方式的分类
		# 面向有连接与面向无连接

		# 电路交换与分组交换
			电路交换（旧技术）- 两台计算机可以独占线路进行数据传输
			分组交换（蓄积交换） - 将数据分成多个数据包，按一定的顺序排列之后分别发送
			分组交换处理过程：发送端将数据分组发送给路由器，路由器收到这些分组数据以后，缓存到自己的缓冲区，然后再转发给目标计算机。
	  
		# 根据接收端数量分类
			单播（Unicast）
			广播（Broadcast）：发给与之相连广播域内的主机
			多播（Multicast）：限定某一组主机作为接收端
			任播（Anycast）  ：发给特定组内的任意一台主机
	
	@1.8 地址
		# 地址的唯一性
		
		# 地址的层次性
			IP地址 = 网络号+主机号

	@1.9 网络的构成要素
		## 传输速率：设备之间数据流的物理速度（bsp:Bits Per Second），单位使时间内传输的数据量（数据吞吐量）
		## 网卡（NIC/网络适配器/网卡/LAN卡）
		## 中继器（repeater）：物理层面上延长的设备，波形调整和再放大。
		## 网桥（2层交换机）：数据链路层面连接连个网络的设备，能够识别数据链路层的数据帧，并将这些数据帧临时存储与内存，
													再重新生成信号作为一个全新的帧发给相连的另一个网络
		## 路由（3层交换机）：根据IP地址进行处理，连接不同的数据链路
		## 4-7层交换机：处理传输层至应用层的数据，分析收发数据，对其进行特定的处理。（负载均衡器）
					应用：广域网加速器，特殊应用数据传输加速以及防火墙
		## 网关 ： 负责将从传输层到应用层的数据进行转换和转发的设备。
*/

/* 第二章 TCP/IP 基础知识
	
	@2.4
	   # TCP/IP 协议分层模型
	   	
	  			OSI参考模型　　　    TCP/IP分层模型                                                                     
	  	 -------------------    -------------------                                    
	  	|      应用层       |  |                   |                           	  |
	  	|-------------------|	 |                   |   DNS,URL,HTML,HTTPTLS/SSL   |           
	  	|      表示层       |  |       应用层      |   SMTP,IMAP               		|     应用程序
	  	|-------------------|  |                   |   MIME,TELNET,SSH,FTP        |       
	  	|      会话层       |  |                   |       ......           			|
	  	|-------------------|  |-------------------|  ----------------------------|------------------                                   
	  	|      传输层       |  |       传输层      |   TCP,UDP,UDP-Lite,SCTP,DCCP |           
	  	|-------------------|  |-------------------|  ----------------------------|     操作系统 
	  	|      网络层       |  |       网络层      |   ARP,IP,ICMP ，IPsec       	|
	  	|-------------------|  |-------------------|  ----------------------------|------------------                                
	  	|    数据链路层     |  |     数据链路层    |   以太网、无线LAN、PPP     	|   
	    |-------------------|	 |-------------------|                              |   设备驱动程序    
	  	|      物理层       |  |       物理层      |        硬件           				|			网络接口
	     -------------------	  -------------------   ---------------------------------------------- 
	  
	  	 OSI注重“通讯协议必要的功能是什么”
	  	 TCP/IP强调“在计算机上实现协议应该开发那种程序”

                              
                              						-------      -------              
                              					 |  TCP  | 		|  UDP  |
                              					  -------      -------
                              						    \          /									运输层
                      -------------------------\--------/--------------------------
                              									\      /
                           --------  					  --------             --------          
                          |  ICMP  | <-------> |   IP   | <-------> |  IGMP  |
                           -------- 	 				  --------             --------
																										|
																										|												网络层													
										                       ---------|---------- 
																					|					|          |
											  	 --------  			|		  --------       |     --------
													|   ARP  | <----|--> |  硬 件 | <----|--> |  RARP  | ARP的内容可根据其包含的IP跨网传输。
													 -------- 	 		|	    --------       |     --------
																					|					|          |
																					|					|		链路层 |
																					|					|          |
	  

		* 硬件（物理层）
		* 网络接口层（数据链路层）
		* 网络层
			** 基于IP地址转发分包数据
			** IP  ：跨网络传送数据包的协议（不具备重发机制，一种不可靠的协议）
			** ICMP（网络控制管理协议）：IP数据包在发送途中一旦发生异常导致无法到达的对端目标地址时，需要给发送端发送一个发生异常的通知
			** ARP（地址解析协议）：从分组数据包的IP地址中解析出物理地址（MAC地址
		* 传输层
			** TCP：面向连接的传输层协议，保证两端通信主机之间的通信可达；能够正确处理在传输过程中丢包、乱序等异常。（不适合音频视频的数据）
			** UDP：面向无连的传输层协议；常用于：分组数据较少或多播，广播通信以及视频通信等多媒体领域。
		* 应用层

	@2.5 TCP/IP 分层模型与通信示例
		#数据包首部
		 --------------------------------------------
		| 以太网包首部 | IP包首部 | TCP包首部 | 数据
		 --------------------------------------------
									 |<-- 以太网中的以太网数据 -->|
									  -----------------------------
									 | IP包首部 | TCP包首部 | 数据
									  -----------------------------
															|<--- IP 数据 --->|
															 -----------------
															| TCP包首部 | 数据
															 -----------------
			附：
			 包：全能性术语
			 帧：数据链路中包的单位
			 数据报：IP和UDP 等网络层以上的分层中包的单位
			 段：TCP数据流中的信息

		#经过数据链路的包
			每个包首部至少都会包含两个信息：1.发送端和接收端地址、2.上一层的协议类型

			 |<---      数据链路层      --->|<---      网络层      --->|<--   传输层  --->|<--- 应用层  --->|<-数据链路层 ->|
			  --------------------------------------------------------------------------------------------------------------
			 | 接收端   | 发送端   | 以太网 | 发送端 | 接收端 |  协议  | 源端口 | 目标端  |      数据       |    循环冗余   |
 			 | MAC 地址 | MAC 地址 |  类型  |   IP   |   IP   |  类型  |   号   |   口号  |                 |      校验     |
			  ---------------------------------------------------------------------------------------------------------------
       |<---       以太网头       --->|<---      IP首部      --->|<-- TCP/UDP首部-->|应用包头及其数据 |以太网Trailer                     
		
		#数据包接收处理
			　 网络接口：主机接收到以太网包后，首先找以太网首部MAC地址判断是否发送自己的包，不是则丢弃，
							     如果是就判断上层协议，IP协议就发送到处理IP的子程序，ARP协议则传给ARP处理。无法识别协议就丢弃。

			-> IP模块 ： 判断IP是否匹配，然后根据上层协议传递到TCP或UDP处理；有路由表的情况下，IP不是自己的地址，借助留有控制表，
									 在调查应该送达的住居或路由以后再转发数据。

			-> TCP模块 ：先计算校验和，判断数据是否被破坏。然后检查是否按照序号接收数据，最后检查端口号，确定具体程序。
									 接收完毕后，接收端则发送一个“确认回执”给发送端。

*/	

/* 第三章 数据链路
		* 不同的数据链路最大的区别之一：最大传输单位（MTU：Maximum Transmission Unit）不同

	@3.1 数据链路的作用
		* 数据链路，有时也指以太网、无线局域网等
		* 定义了通信媒介互联的设备之间传输的规范 （通信媒介包括：双脚电缆、同轴电缆、光纤、电波以及红外线）
		* 数据链路的段：一个被分割的网络
			** 两条数据链路：
				*** 网络层的概念看：逻辑上是一个网络 ---> 这两条网线组成一个段。
				*** 物理层的概念看：两条线风别是两个物体 ---> 一条网线一个段。

	@3.2 数据链路的相关技术
		# MAC地址
			* 用于识别数据链路中互连的节点（互连同一种数据链路的节点之间进行包传递）
			* MAC 地址长48比特：
			 |1|2|3                24|25                    48|   
			  ------------------------------------------------
			 | | |       厂商识别码  |   内识别码             |
			  ------------------------------------------------
				第1位：单播地址0/多播地址1
				第2位：全局地址0/本地地址1
			*MAC地址并不总是唯一，实际上即使MAC地址相同，只要不是同属一个数据链路就不会出现问题。

		# 共享介质型网络
			* 半双工
			* 设备之间使用同一个载波信道进行发送和接收
			* 共享一个通信介质
			* 对介质进行控制访问
				** 争取方式 和 令牌传递方式

		# 非共享介质网络
			* 传输控制方式
			* 网络的每个节点直连交换机，由交换机负责转发数据帧
			* 半双工和全双工
			 ** 半双工： 只发送或直接收的通信方式
			 ** 全双工：允许在同一时间既可以发送数据也可以接收数据。

		# 根据 MAC 地址转发
			* 以太网交换机就是持有多个端口的网桥。根据链路层中每个帧的目标MAC地址，决定从哪个网络接口发送数据。
			* 交换机的转发方式：
				** 存储转发： 检查以太网数据帧末尾的FCS后再进行转发。
				** 直通转发： 不需要将整个帧接收下来以后再转发。快，但不可避免有发错误帧的可能性。

		#环路检测技术
			* 生成树：网桥间每1~10秒内相互交互（Bridge Protocol Data Unit）包，从而判断哪些端口使用哪些不使用，以消除环路。
								一旦发生故障，自动切换通信线路。
			* 源路由：

		#VLAN（Virtual Local Area Network）
			* 网桥/2层交换机按照端口区分了多个网段，从而区分了广播数据传播的范围、减少网络负载并提高网络安全。

	@3.3 以太网
		# 连接形式：终端与交换机之间独占电缆的方式

		#分类

		#帧格式
			* 以太网帧前端有一个前导码部分，由0、1交替组合而成，表示以太网帧开始，也是对端网卡能够确保与其同步的标志。
				前导码末尾有一个SFD（STAR FRAME DELIMITER）域，值为0b11.共8字节。
			* 格式：
			 ---------------------------------------------------------------------------------------------
			| 目标MAC地址（6地址）| 源MAC地址（6字节）| 类型（2字节）| 数据（46-1500字节） | FCS（4字节） |
			 ---------------------------------------------------------------------------------------------
 		  * 数据链路分两层：介质访问控制（MAC：Media Access Control)、逻辑链路控制（LLC：Logical Link Control）。

	@3.4 无线通信

	@3.5 PPP（Point-to-Point）
		
*/

/* 第四章 IP协议
	@4.1 IP 即网际协议
		* 主要由IP（Internet Protocol）和ICMP（Internet Control Message Protocol）组成。

		#OSI第三层
			* 跨越不同的数据链路，实现终端节点之间的通信。

	@4.2 IP基础
		* 三大模块：IP寻址、路由、IP分包与组包

		#路由控制
			* Hop : 跳，指主机或路由器网卡不经其他路由器而能直接到达的相邻的主机或路由器网卡之间的一个区间。（一跳）
			* 路由控制表：记录IP数据在下一步应该发给哪个路由器。

		#IP：面向无连接
			* 原因：简化、提速

	@4.3 IP地址的基础知识
		* 用于地址识别主机和路由
		# IP地址由网络和主机两部分标识组成
			* 网络标识必须保证相互连接的每个段的地址不相重复。

		# IP地址的分类
			* A类： 网络地址 0.0.0.0 ~ 127.0.0.0
			   00000000.|00000000.00000000.00000000
				 01111111.|00000000.00000000.00000000
				 --------------------------------------
				|0|        | ****** | ****** | ******  |
				 --------------------------------------
				  | 7 bit  |  8 bit |  8 bit |  8 bit  |
			* B类： 网络地址 128.0.0.0 ~ 191.255.0.0
				10000000.00000000|.00000000.00000000
				10111111.11111111|.00000000.00000000
				 --------------------------------------
				|1|0|       |        | ***** |  ****** |
				 --------------------------------------
				    | 6 bit |  8 bit |  8 bit|  8 bit  |

			* C类： 网络地址 192.0.0.0 ~ 223.255.255.0
				11000000.00000000.00000000|.00000000
				11011111.11111111.11111111|.00000000
				 --------------------------------------
				|1|1|0|     |        |       | ******* |
				 --------------------------------------
							|5 bit|  8 bit | 8 bit |  8 bit  |
			* D类： 网络地址 224.0.0.0 ~ 239.255.255.255 / IP多播类
				11100000.00000000.00000000|.00000000
				11101111.11111111.11111111|.00000000
				 --------------------------------------
				|1|1|1|0|    |       |        |        |
				 --------------------------------------
								|4bit| 8 bit |  8 bit | 8 bit  |
			* 主机地址：全为0表示对应的网络地址或ip地址不可获知的情况下才使用，
									全为1作为广播地址；因此，C类地址每个网段最多只能有2^8 - 2 = 254个主机地址。

		# 广播地址
		 * IP地址中主机地址部分全部设置为1.
		 * 广播分为：本地广播和直接广播
			** 本地广播：本地网络内广播，会被路由屏蔽，不会发送到该网段以外其他的链路上。
			** 直接广播：广播的到另一个网段（暂时这么理解）

		# 多播
			* 多播使用D类地址
			* 划分：
				** 局部多播地址：224.0.0.0 ~ 224.0.0.255 之间，路由协议和其他用途保留的地址，路由器不转发此范围 IP 包，在同一链路内也能实现多播。
				** 预留多播地址：224.0.1.0 ~ 238.255.255.255 之间，可用于全球范围或网络协议
				** 管理权限多播地址：239.0.0.0 ~ 239.255.255.255 之间，可供组织内部使用，类似于私有IP，可限制多播范围。

		# 子掩码
			* 网络标识相同的计算机必须在同一链路。
	
	@4.4 路由控制
		* 路由控制表形成方式：
			** 静态路由控制：手动设置
			** 动态路由控制：路由器间交换信息时自动刷新

		# IP地址与路由控制
			* IP地址的网络地址部分用于进行路由控制
			* 默认路由：任何一个地址都能与之匹配的记录
			* 主机路由：（IP地址/32）整个IP地址的所有位都将参与路由。（会导致路由表膨大，路由负荷增加，进而造成网络性能下降）
			* 环回地址：在同一台计算机上的程序进行网络通信时所使用的一个默认地址。（127.0.0。1|localhost）数据包不会流向网络。

	@4.5 IP 分割处理与再构成处理
		# 数据链路不同，MT则不同
			* IP 的MTU 65535 Byte
			* 以太网MTU ： 1500 Byte
		
		# IP 报文的分片与重组
			* 路由器虽然进行分片，但不会重组；由目标主机进行IP数据报重组。

		# 路径MTU发现

	@4.6 IPv6
		# IPv6 的必要性：为了根本解决IPv4地址耗尽的问题
		...

	@4.7 IPv4 首部
			0				3	|				7 |               15|16  18|19                    31 | 
			 ----------------------------------------------------------------------  -----  ---
			| Version |   IHL   | Type of Service |           Total Length         |   |     |
			|-------------------------------------|--------------------------------|   |     | 
			|							Identification          | Flag |      Fragment offset    |   |     |
			|----------------------------------------------------------------------|   必    IP
			|   Time To Live    |     Protocol    |          Header Checksum       |   要    首
			|----------------------------------------------------------------------|   部    部
			|                             Source Address                           |   分    |
			|----------------------------------------------------------------------|   |     |
			|                            Destination Address                       |   |     |
			|----------------------------------------------------------------------| -----   |
			|                           Options                      |   Padding   |         |
			|----------------------------------------------------------------------|        --- 
			
			* Type of Service ：8 bit,表明服务质量。
				** bit 0，1，2: 优先度；0 ~ 7 的优先度，从0到7优先度从低到高
				** bit 3: 最低延迟
				** bit 4: 最大吞吐
				** bit 5: 最大可靠性
				** bit 6: 最小代价
				** bit 7: 未定义
			* Identification: 用于分片重组
			* Flag: bit 0-未使用 bit 1- 0可分片、1不能分片 ，bit 2 - 0最后一个分片、1分片中段的包
			* Fragment Offset: 分片的每一个分段相对于源数据的位置
			* TTL: 指可以中转多少个路由，每经过一个路由减1，直到变成0则丢弃该包。

*/

/* 第五章 IP协议相关技术
	* 相关协议:DNS、ARP、ICMP、DHCP

	@5.1 凭IP无法完成通信
	
	@5.2 DNS （Domain Name System）
		
	@5.3 ARP
		
		 ----------------------------------------------------------
		|			  	硬件类型			  	 |           协议类型          |
		|----------------------------------------------------------|
		|     HLEN     |    PLEN     |            操作码           |
		|----------------------------------------------------------|
		|                      发送端 MAC 地址                     |
 	 	|----------------------------------------------------------|
		|    发送端 MAC 地址（续）   |				 发送端IP 　　　　　 |
		|----------------------------------------------------------|
		|         发送端IP           |      接收端 MAC 地址        |
		|----------------------------------------------------------|
		|                   接收端 MAC 地址（续）          　　　　|
		|----------------------------------------------------------|
		|                        接收端IP　                        |
		 ----------------------------------------------------------

		例：                                                         ARP使用的                               OP指示当前包是                                       在arp请求包
			      广播                              ARP包  |          |是IP协议 |                            |请求包还是应答包|                                 | 里也可以是其他数据|
		| ff ff ff ff ff ff | 00 0c f1 d4 d9 60 | 08 06  |  00 01   |  08 00  |     06             04      | 0x0001|0x0002  | 00 0c f1 d4 d9 60 | c0 a8 01 0f | 00 00 00 00 00 00 | c0 a8 01 02 |
		 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		|      目的MAC      |       源MAC       | 帧类型 | 硬件类型 | 协议类型 | 硬件地址长度| 协议地址长度|       op       |      发送者MAC    | 发送者IP地址|   需要请求的MAC   |    目标IP   |          
		 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		|                链路层  以太网帧头              |


		* 以目标IP地址为线索，用来定位下一个应该接收数据分包的网络设备对应的MAC地址。
		
		# ARP的工作机制
			* 广播一个ARP包，同链路的节点接收到后检查IP是否自己的IP，若是则返回一个带有自己MAC地址的ARP响应数据包。

	@5.4 ICMP(Internet Control Message Protocol)
		
			------------------------------------------------------
		 |                   IP头部（20字节）                   |
 		  ------------------------------------------------------
		 | 类型（0、8）| 代码 （0）|           校验和           |
		  ------------------------------------------------------
		 |          标识符         |           序列号           |        
		  ------------------------------------------------------
		 |                     选项 （若有）                    |
		  ------------------------------------------------------


		# 辅助IP：1、确认IP包是否成功送达目标地址，通知在发送过程当中IP包被废弃的具体原因。
			* ICMP两类：1、通知出错原因的错误消息。2、用于诊断的查询消息。

		#主要的ICMP消息
			* 目标不可达消息
			* 重定向消息
			* 超时消息：TTL = 0 时。
			* 回送消息：ping 命令的实现 -- 向对端主机发送回送请求消息（ICMP Echo Request Message），接收回送应答消息。
			            Ping操作中就包括了相应请求（类型字段值为8）和应答（类型字段值为0）ICMP报文。
									一台主机向一个节点发送一个类型字段值为8的ICMP报文，如果途中没有异常
									（如果没有被路由丢弃，目标不回应ICMP或者传输失败），则目标返回类型字段值为0的ICMP报文，说明这台主机存在

	@5.5 DHCP （Dynamic Host Configuration Protocol）
		# DHCP 实现即插即用

		# DHCP 工作机制
			* DHCP服务器（网段的路由器很多时候充当服务器） --> 将DHCP要分配的IP地址设置到服务器上 (设置相应的子掩码、路由控制信息，DNS服务器地址) 
			* DHCP 中获取IP地址：
				** 1、DHCP客户端发送 DHCP发现包：要求设置IP地址和子网掩码
				   2、DCHP服务器返回 DHCP提供包：通知可以使用的网络设置
				** 3、DHCP客户端发送 DHCP请求包：通知想要使用在2中通知的设置
					 4、DHCP服务器返回 DHCP提供包：通知允许3的设置
			* DHCP的确认之所以分两个阶段，是为了保证及时在DHCP服务器上重复设置也可以能正常工作
			* DHCP 服务器和客户端必须具备以下功能：
				1、 DHCP服务器：在分配IP地址钱发送ICMP会送请求包，确认没有返回应答。
				2、 DHCP客户端：针对从DHCP那里获取的IP地址发送ARP请求包，确认没有返回应答

		# DHCP中继代理
												
	@5.6 Nat(Network Address Translator)
		* 在本地网络使用私有地址，在连接互联网时转而使用全局IP地址的技术。
		* 本地网络与外部网络主机通信时：发送时Nat路由器根据地址转换表修改 源IP，接收数据时修改目标IP，同时修改相应的UDP/TCP首部的checksum.
		# 潜在问题：
			* 无法从NAT的外部向内部服务器建立连接。
			* 转换表生成与操作会产生开销
		

	@5.7 IP 隧道
		
	@5.8 其他IP相关技术
		# IP多播相关技术
			* MLD（Mutilcast Listener Discovery）通过 IGMP 实现，用于确认多播接收端是否存在。
			* IGMP(Internet Group Management Protocol) 主要两大作用：
				1、向路由器表明想要接收多播消息（并通知想接收多播的地址）
				2、向交换集线器通知想要接收多播的地址　o（IGMP探听<MLD>）
				** 首先，路由器会根据1的作用， 了解到想要接收多播的主机，并将这个消息告知给其他路由器，准备接收多播消息。
					 其次，通常，在交换集线器中，多播帧和广播帧一样不经过滤就回全部被拷贝到端口上，这样会导致网络负荷加重；
							 MLD可以过滤多播帧；在MLD探听的交换集线器对通过的IGMP包进行监控。由于从MLD报中可获知多播发送的地址和端口，
							从而不会再像毫无关系的端口发送多播帧。这可以减轻哪些不接受多播消息的端口的负荷。
			* IGMP报文封装在IP报文中

		# IP 任播
			
		# Moble IP
			* 移动主机：移动了位置，IP地址却不变的设备。在没移动的时候，所连接的网络叫做归属网络，IP地址叫做归属地址。
			* 归属代理：处于归属网络下，可监控移动设备的位置，并转发数据包给移动主机。类似注册户籍信息的机关。
			* 外部代理：使用于支持移动主机的移动设备。
 
 @6.3 UDP
	* 常用于：
		** 包总量较少的通信（DNS、SNMP等）
		** 视频、音频等多媒体通信（即时通信）
		** 限定于LAN等特定网络中的应用通信
		** 广播通信（广播、多播）
*/

/* 第六章 TCP与UDP
	
	@6.1 传输层的作用
		# 两种传输层协议TCP和UDP
		　* TCP：面向连接的、可靠的流协议。
		  * UDP：不可靠数据报协议。

		# TCP 与 UDP 区分
			* TCP：用于有必要实现可靠传输的情况。具备顺序控制、重发控制等机制。
			* UDP：主要用于对高速传输和实时性比较高要求的通信或广播通信。
	
	@6.2 端口号
		# 通过IP地址、端口号、协议号进行通信识别。
		　* IP 和 端口 全都一样，只是协议号不同，也认为两个不同的通信。

		# 确定端口号
			* Well-Known Port Number: 0 ~ 1023
			* 被正式注册：1024 ~ 49151
			* 系统动态分配：在之前分配的号码的基础上加1.49152 ~ 65535 

		# 端口号与协议
		 * 数据到达IP层后，先检测IP首部中的协议号，再传给相应的协议模块。
			 如果是TCP则传给TCP模块，如果是UDP则传给UDP模块去做端口号的处理。
			 即使是同一个端口号，由于传输协议是各自独立地进行处理，因此相互之间不会受到影响。

	@6.4 TCP
		* TCP 可以进行丢包是的重发控制，还可以对次序乱掉的分包进行顺序控制。
		* 作为面向连接协议，只有确认通信对端存在时才会发送数据，从而控制流量的浪费。

		# TCP的特点及其目的
			* 通过IP数据报实现可靠性传输，解决数据的破坏、丢包、重复以及分片顺序混乱等问题
			* 通过检验和、序列号、确认应答、重发机制、连接管理以及窗口控制等机制实现可靠性。

		# 通过序列号与确认应答提高可靠性
			* 数据到达主机，接收端主机返回一个确认应答ACK（Positive Acknowledgement）
			* 序列号（确认应答号），初始值并非为0，二十在建立连接以后由随机数生成。
				而后面的计算则是对每一字节加一。

		# 超时重发如何确定
			* 每次发包时都会计算往返时间（Round Trip Time）及其偏差（RTT时间波动的值、方差），其和为超时时间。
		
		# 连接管理
			* "三次握手、四次挥手"

              				 --------                             --------
              				| Client |                           | Server |
              				 --------                             --------
              				    |        SYN_1(请求建立连接)         |
              						| ------------------------------->   |
              						|                                    |
              						|        ACK_1(SYN_1的确认应答)      |
              						|          SYN_2(请求建立连接)       |
              						| <-------------------------------   |
              						|                                    |
              						|       ACK_2(SYN_2的确认应答)       |
              						| -------------------------------->  |
              						|         .                          |
              						|         . （连接建立完成）         |
              						|         .                          |
              						|                                    |
              						|        FIN_1（请求切断连接）       |
              						| ------------------------------->   |
              						|                                    |
              						|        ACK_1(FIN_1的确认应答)      |
              						| <------------------------------    |
              						|                                    |
              						|        FIN_2（请求切断连接）       |
              						| <------------------------------    |
              						|                                    |
              						|        ACK_2(FIN_1的确认应答)      |
              						| ------------------------------->   |
              						|                                    |

		
			* 状态变迁：
											--------                             --------
									   | Client |                           | Server |
											--------                             --------
												  |                                    |  LISTEN (被动打开)
													|        SYN_1(请求建立连接)         |
				主动打开SYN_SENT  | ------------------------------->   |  SYN_RCVD
													|                                    |
													|        ACK_1(SYN_1的确认应答)      |
													|          SYN_2(请求建立连接)       |
						 ESTABLISHED  | <-------------------------------   |
													|                                    |
													|       ACK_2(SYN_2的确认应答)       |
													| -------------------------------->  |  ESTABLISHED
													|         .                          |
													|         . （连接建立完成）         |
													|         .                          |
													|                                    |
													|        FIN_1（请求切断连接）       |
			主动关闭FIN_WAIT_1	| ------------------------------->   |  
													|                                    |  CLOSE_WAIT (被动关闭)
													|        ACK_1(FIN_1的确认应答)      |
						  FIN_WAIT_2	| <------------------------------    |
													|                                    |
													|        FIN_2（请求切断连接）       |
													| <------------------------------    |  LAST_ACK
													|                                    |
							TIME_WAIT		|        ACK_2(FIN_1的确认应答)      |
													| ------------------------------->   |  CLOSED
													|                                    |

				 ** 当TCP执行一个主动关闭，并发回最后一个ACK，该连接必须在TIME_WAIT状态停留的时间为2倍的MSL。
				 ** TIME_WAIT状态会等待2MSL(Maximum Segment Lifetime)时间，
						这样可以让TCP再次发送最后的ACK_2，以防这个ACK_2丢失而另一端超时并重发最后的FIN_1.
				 ** MSL:RFC 793[Postel 1981c] 指出MLS为2分钟。然而，现实中的常用值为30秒，1分钟或2分钟。
				 ** 在连接处于TIME_WAIT（2MSL）的状态时，任何迟到的报文段将被丢弃。
						因为处于2MSL等待的、有该socket pair定义的连接在这段时间内不能被再用，
						因此当要建立一个新的有效连接时，这个新连接的报文相当于该连接的较早的迟到的报文段，而被丢弃。

		# TCP以段为单位发送数据
		 * 在建立连接时，请求连接SYN包的TCP头附加4字节的MSS（Maximun Segment Size）信息，告知最大消息长度。
		 * 最理想的情况是，最大消息长度正好是IP中不会被分片处理的最大数据长度。

		# 利用窗口控制提高速度
    
		# 窗口控制与重发控制
			* 接收端在没有收到所期望的序号的数据时，会对之前收到的数据进行确认应答。
			*发送端则一旦收到某个确认应答后，又连续3次收到同样的确认应答，则认为数据段已经丢失，需要进行重发。

		# 流控制
			* 接收端主机向发送端主机通知自己可以接收数据的大小，于是发送端会发送不超过这个限度的数据。该大小限度被称作窗口大小。
			* TCP首部用一个字段来通知窗口大小。
			* 接收端缓冲区一旦面临数据溢出，窗口大小的值也随之被设置为一个更小的值通知给发送端。
				也就是说发送端主机会根据接收端主机的指示，对发送数据的量进行控制。
			* 发送端会时不时的发送一个窗口探测的数据段

		# 拥塞控制
		
		# 提高网络利用率的规范

		# 使用TCP的应用

	@6.5 其他传输层协议
		# UDP-Lite （Lightweight User Datagram Protocol）

		# SCTP （Stream Control Transmission Protocol
			* 以消息为单位收发：TCP中接收端并不知道发送端应用所决定的消息大小。在SCTP中可以。
			* 支持多重宿主：在有多个NIC的主机章，即使其中能够使用的NIC发生变化，也仍然可以继续通信。
			* 支持多数据流通信
			* 可以定义消息的生存期限：超过生存期限的消息，不会被重发。
			* 主要用于进行通信的应用之间发送众多较小消息的情况。

	@6.6 UDP 首部的格式
		* 由源端口号、目标端口号、包长和校验和组成
		 0                      15 16                      31
		 |------------------------|-------------------------|--- 
		 |                   32 位源IP地址                  |
		 |--------------------------------------------------|
		 |                   32 位目的IP地址                |  构造 UDP 伪首部
		 |--------------------------------------------------|
		 |     0     |8位协议(17) |    16 位UDP长度         |
 		 |--------------------------------------------------|---
		 |       Source Port      |  			Destination Port	|																					
		 |--------------------------------------------------|
		 |         Length         |         Checksum        | UDP 首部
		 |--------------------------------------------------|
		 |                     数据部分                     |
		 |__________________________________________________|

		 * length（包长度）：UDP首部长度和数据长度之和。

		* 校验和的计算：构造伪首部后，以16位（short 类型）将除了Checksum字段以外的所有字段构成的值相加（最高位进位，那么需要对结果进行回卷），之后取反则为校验和值。
		例：
		0                       15 16                      31
		 |------------------------|-------------------------|  --- 
		 |            192.168.1.106 (0xc0a8 0x016a)         |		|
		 |--------------------------------------------------|   
		 |           11.111.111.111 (0x0b6f 0x6f6f)         |  UDP 伪首部 
		 |--------------------------------------------------|（个人理解：其实就是在IP头部提取地址、协议的值，为了便于理解抽象成所谓的伪首部）
		 |     0     | (17)(0x11) |        17 (0x11)        |   |
 		 |--------------------------------------------------|  ---        ---------------------------------------------------------------------
		 |       63549（0xf83d）  |  		 12345(0x3039)	    |						 | 结果回卷示例：					
		 |--------------------------------------------------|						 |    	（一字节）0b    0 1 0 0  0 1 0 1					
		 |        17(0x11)        |    0xb12 (取反后的值)   |  UDP 首部	 |    				   	   +  1 0 1 1  1 1 0 1     
		 |--------------------------------------------------|						 |    							---|----------------  
		 |  hello UDP (0x6865 0x6c6c 0x6f20 0x5544 0x5000)  |            |                    1 0 0 0 0  0 0 1 0    
		 |__________________________________________________|   				 |    
		                                                                 |    最高位回卷后值:   0 0 0 0  0 0 1 1  就算溢出，回卷后也不丢失信息。
																																		 |    取反后为校验码:   1 1 1 1  1 1 0 0 
																																		 |    十六进制表示 ==>  0xFC

	  * 校验和计算中计算UDP伪首部的理由：
			TCP/IP 中识别一个进行通信的应用需要5大要素：源IP、目标IP、源端口、目标端口、协议号。
			而传输层UDP和TCP协议中只有两个端口号，其他三项都在网络层IP协议中，假定其他3项信息被破坏，
			这极有可能导致应该收到包的应用收不到包，不该收到包的应用却收到了包，为了避免这样的问题，
			有必要验证一个通信中必要的5项识别吗是否正确。

	 @6.7 TCP 首部格式

				 0                      15 16                      31
		 |------------------------|-------------------------|-----------------
		 |                   32 位源IP地址                  |
		 |--------------------------------------------------|
		 |                   32 位目的IP地址                |  构造 TCP 伪首部
		 |--------------------------------------------------|
		 |     0     |8位协议(17) |    16 位TCP长度         |
 		 |--------------------------------------------------|-----------------
		 |       Source Port      |  			Destination Port	|																					
		 |--------------------------------------------------|
		 |                   Sequence Number                |
		 |--------------------------------------------------|
		 |							Acknowledgement Number              |         
		 |--------------------------------------------------|   TCP 首部 :没有表示包长度和数据长度的字段
		 |offset|reserved|ctr flag|     Window Size         |
		 |--------------------------------------------------|
		 |       Checksum         |      Urgent Pointer     | 
		 |--------------------------------------------------|
		 |         Options        |         Padding         |
		 |--------------------------------------------------|---
		 |                     数据部分                     |
		 |__________________________________________________|

		 * Sequence Number : 32位，是指发送数据的位置，每发送一次数据，就累加一次该数据字节数的大小。
												 序列号不会从 0 或 1 开始，在建立连接时由计算机生成的随机数作为初始值，通过SYN包传给接收端。
		 * Data Offset : 表示TCP所传输的数据部分应该从哪个位置开始计算，也可把它看作TCP的长度。
		 * Control Flag:
        0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15			
			|-----------|-------------------|-------------------------------|
			| Offset    |     Reserved      |CWR|ECE|URG|ACK|PSH|RST|SYN|FIN|
			 ---------------------------------------------------------------
			 ** CWR (Congestion Window Reduced) 拥堵窗口处理 ,标识为 1 时，通知对方已将拥塞窗口缩小
			 ** ECE (ECN-Echo）: 标识为1时，通知对方这边的网络拥塞。在收到数据包的IP首部中ECN为1时将TCP首部的ECE设置为1.
			 ** URG（Urgent Flag）: 标识为1，有需要紧急处理的数据。
			 ** ACK ：确认人大的字段变为有效。TCP规定，除了最初建立连接时的SYN包之外，改为必须设置为1.
			 ** PSH（Push Flag）：表示需要将收到的数据立刻上传给上层应用协议。
			 ** RST (Rest Flag) ：表示为1，表示TCP连接中出现异常必须强制断开连接。
			 ** SYN（Synchronize Flag）：用于建立连接。1表示希望建立连接，并在其序列号的字段进行序列号初始值设定。
			 ** FIN（Fin Flag）: 1表示今后不会再有数据发送，希望断开连接。
													 通信结束希望断开连接时，通信双方的主机之间互相交换FIN位置为1的TCP数据段。
													 每个主机对对方的FIN包进行确认应答以后就可以断开连接。
													 主机收到FIN设置为１的TCP段以后不必马上回复一个FIN包，
													 而是可以等到缓冲区的所有数据都因已成功发送而被自动删除后再发。

*/

/*　第七章　路由协议
	@7.1 路由控制的定义

		# IP 地址与路由控制

		# 静态路由与动态路由
			* 静态路由一旦发生故障，无法自动绕过故障节点，需要手工设置后才能恢复正常。
		
		# 动态路由的基础
			* 相邻的路由器间会发送自己已知的网络连接信息，而这些信息将依次接力传递给其他路由。

	@7.2 路由的控制范围
		* 使用IGP（Interior Gateway Protocol）和 EGP（Exterior Gateway Protocol）两种类型的路由协议。

	@7.3 路由算法
		# 距离向量算法（distance - vector）：根据距离（路由器的个数）和方向决定目标或目标主机位置的方法
			* 每个路由掌握的信息不同，通往每个网络所耗的距离也根据路由器的不同而不同，因此该算法的一个缺点就是不容易判断每个路由器上的信息是否正确

		# 链路状态算法（Link - state）：路由在了解网络整体连接状态的基础上生成路由控制表的一种方法。
			* 每个路由必须保持同样的信息才能进行正确的路由选择
		
	@7.4 RIP
		*RIP（Routing Information Protocol）是距离向量型的一种路由协议，广泛用于LAN。

		# 广播路由控制信息
			* RIP将路由控制信息定期（30秒一次）向全网广播。如果没有收到路由控制信息，连接就被断开。

		# 根据距离向量确定路由
			* RIP 基于距离向量算法决定路径。
			* 距离（Mertircs）单位为"跳数"，指所经过路由器的个数。
		

		后面的先忽略。。。。。。。。。
		

*/

/* 第八章 应用协议
	@8.2 远程登录
		* 主要使用TELNET 和 SSH（Secure SHell）两种协议。

		#TELNET
			* 利用TCP的一条连接，通过这一个条连接向主机发送文字命令并在主机上执行。
			* 分为两类基本服务：仿真终端功能 和 协商选项机制。
	  #SSH：加密的远程登陆系统
		
	@8.3 文件传输 FTP
		* 工作机制：使用两条TCP连接，一条用来控制，另一条用于传输数据。
		* 控制连接21端口，子啊21端口上进行文件的GET（RETR）、PUT（STOR）、以及文件一览（LIST）等操作是，
			每次都会建立一个用于数据传输的TCP连接。数据传输完毕后该连接就会断开。
		* 数据传输的连接时按照与控制连接相反的方向建立的。
		* 数据传输的连接通常使用20断开。

	@8.4 电子邮件
		# 工作机制
			* SMTP (Simple Mail Transfer Protocol)使用TCP协议。
			* 三部分组成：邮件地址、数据格式以及发送协议。

		# 邮件地址
			电子有见地发送地址由DNS 进行管理。DNS中注册有邮件地址及其作为发送地址时对应的邮件服务器的域名。

		# MIME（Multipurpose Internet Mail Extensions）	
			* 电子邮件所能发送的数据类型已被扩展到MINE：静态图像、动画、声音、程序等各种形式数据。

		# SMTP：电子邮件协议，使用TCP的25号端口。
			* 建立一个TCP连接以后，在这个连接上进行控制和应答以及数据发送。
			* 客户端以文本的形式发出请求，服务端返回一个3位数字的应答。
			* 每个指令和应答的最后都必须追加换行指令（CR、LF）。

		
		# POP 
		  * 是一种用于接收电子邮件的协议。

		# IMAP (Internet Message Access Protocol)
			* 与POP类似，也是接收电子邮件的协议。
			* 在POP中邮件由客户端进行管理，而在IMAP中邮件由服务器进行管理。
			
	@8.5 WWW
		# WWW基本概念
			*	访问信息的收端与位置（URI，Uniform Resource Identifier）、信息的表现形式（HTML,HyperText Markup Language）
				信息转发（HTTP，HyperText Transfer Protocol）
			* URI：用于标识资源。
			* URL（Uniform Resource Locator）表示资源的具体位置。 
		
		# HTML

		＃HTTP
			* 工作机制：客户端向80端口建立一个TCP连接，然后再这个TCP连接上进行求和应答以及数据报文的发送。
			* 1.0版本中再每一个命令和应答都会触发一次TCP连接的建立和断开。
				而1.1开始，允许在一个TCP连接上发哦是那个多个命令和应答。（Keep-alive）

		# JavaScript、CGI、Cookie
			* CGI(Common Gateway Interface)：Web服务器调用外部程序时所使用的一种服务端应用规范。

	@8.6 网络管理
		#SNMP（Simple Network Management Protocol）

	@8.7 其他应用层协议
		# 多媒体通信技术
			* TCP 有流控制、拥堵控制、重发控制等功能，有时应用所发出去的数据可能无法迅速达到对端目标。
				在注重系统的即时性，多媒体通信中采用UDP。
			* H.323：用于在IP网上传输音频、视频的一种协议。
				定义了4个主要组件：
					终端、网关（吸收用户数据压缩顺序的不一致性—）、网闸（电话本管理、呼叫管理）以及多点控制单元（允许多个终端同时使用）
					
																 ---------------------------------------------- ----
																|  数据通信T.120 | 传输控制H.245 | 音频 | 视频 |
																|                |               |-------------|  H.323 协议栈
																|                |               |  RTP  RTCP  |
																|----------------------------------------------| ----
																|            TCP         |         UDP         |
																|----------------------------------------------|
																|                       IP                     |
																|----------------------------------------------|
																|                    数据链路                  |
																 ----------------------------------------------

			* SIP(Session Initiation Protocol)
				与 H.323 相对的TCP/IP协议。
				终端之间进行多媒体通信时，需要具备事先解析对方地址、呼出对方号码并对所要传输的媒体信息进行处理等功能。
													
																 ----------------------------------------------  
																|                                | 音频 | 视频 |
																|           传输控制             |-------------|  
																|            SIP SDP             |  RTP  RTCP  |
																|----------------------------------------------|  
																|            TCP         |         UDP         |
																|----------------------------------------------|
																|                       IP                     |
																|----------------------------------------------|
																|                    数据链路                  |
																 ----------------------------------------------

			* RTP（Real-Time Protocol）
				为每个报文附加时间戳和序号。

		# P2P
				
*/

/* 第九章 网络安全

	@9.4 安全协议
		# IPsec 与 VPN（Virtual Private Network,虚拟专用网络）
			* IPsec:IP 首部的后面追加“封装安全有效载荷（Encapsulating Security Playload）”和“认证首部(Authentication Header)”
			* 传输模式：
					   ------------------------------	                        -----------------------------	
						|         ----								 |                       |         ----								 |
						|        |DATA|								 |  										 |        |DATA|							 |
						|         ----								 |  										 |         ----								 |
						|       		|									 |  										 |       		|									 |
						|         --------						 |  										 |         --------						 |
						|        |DATA|TCP|						 |  										 |        |DATA|TCP|					 | 
						|         --------						 |  										 |         --------						 |
					  | 				|  	加密						 |  										 |          | 解密             |
					  |  -------|--------|-------		 |  										 |  -------|--------|-------	 | 
					  | |ESP认证|DATA|TCP|ESP首部|	 |  										 | |ESP认证|DATA|TCP|ESP首部|	 |
					  |  ------------------------		 |  										 |  ------------------------	 | 
					  | 					|									 |  										 |          |                  |
						| ---------------------------	 |  		NETWORK 				 | --------------------------- |	 
						||ESP认证|DATA|TCP|ESP首部|IP| |    ----------->			 ||ESP认证|DATA|TCP|ESP首部|IP||
						|	---------------------------  |  										 | ----------------------------| 
						 ------------------------------	                        ------------------------------

		  * 隧道模式
		 　　　　	    ___________                   _______|_加密______|__________                ___________      
						     |DATA|TCP|IP｜                |ESP认证|DATA|TCP|IP|ESP首部|IP|              |DATA|TCP|IP｜
				[主机A] ----------------> [VPN路由A] --------------------------------->[VPN路由B] -----------------> [主机B]
				
		# TLS/SSL(Transport Layer Security / Secure Socket Layer)与 HTTPS
			* TLS/SSL 先通过非对称加密发送对称加密的密钥，然后通过对称加密通信。
							
											[客户端]  											              [web服务器]
													|                                              |  
													|  发送HTTPS请求（通知可支持的加密算法）       |
													| -------------------------------------------> |
													|			    												             |
													|		发送公钥和电子证书（被认证中心的私钥加密） |												               
													|	<------------------------------------------- |															              
													|																               |
          确认电子证书		|																               |
        确认公钥是否为		|																               |
     刚才访问的服务器所属 |																               |
     							        |	 发送 用web服务器的公钥加密对称加密的私钥		 |
							            | -------------------------------------------> |
													|                                              |
													|          使用对称加密进行加密通信            |
													|      <------------------------------>        |
													|                                              |

*/

/* 附：socket 编程
	# 基础知识
		* Little endian：低字节存储在起始地址
		* Big endia：高字节存储在起始地址
		* 网络字节序为 big endian。
		* 每个TCP SOCKET 有一个发送缓冲区和一个接收缓冲区，
			接收缓冲区的大小就是通知另一端的窗口大小，对方不会发送大于该窗口大小的数据。
		* UDP SOCKET只有一个接收缓冲区无流量控制，当接收的数据报溢出时就会被丢弃。
		* 当TCP通信服务端监听到一个对端连接后，产生的一个通信标识socket = （对端）IP + （对端）PORT。
		*  个人理解：
																		
																			IP层消息处理
                                           |
														根据上层协议号 |    UDP处理 端口区分
                                           |---------------------socket
                                           |
																			TCP 处理 （由报文头flag标识区分）
                                    /      |
                                   /       | （根据本地IP+监听端口）
                                  /	     SOCKET
                                 /         |
													socket：使用对端IP＋PORT产生通信标识
                                           

*/


#endif // !_NOTE_TCP_IUP_H_
