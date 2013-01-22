USE [master]
GO
/****** Object:  Database [MCS]    Script Date: 2013/1/22 11:48:33 ******/
IF  EXISTS (SELECT name FROM sys.databases WHERE name = N'MCS')
DROP DATABASE [MCS]
GO
/****** Object:  Database [MCS]    Script Date: 2012/12/18 17:38:14 ******/
IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = N'MCS')
BEGIN
CREATE DATABASE [MCS]
END
GO
ALTER DATABASE [MCS] SET COMPATIBILITY_LEVEL = 110
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [MCS].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [MCS] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [MCS] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [MCS] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [MCS] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [MCS] SET ARITHABORT OFF 
GO
ALTER DATABASE [MCS] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [MCS] SET AUTO_CREATE_STATISTICS ON 
GO
ALTER DATABASE [MCS] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [MCS] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [MCS] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [MCS] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [MCS] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [MCS] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [MCS] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [MCS] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [MCS] SET  DISABLE_BROKER 
GO
ALTER DATABASE [MCS] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [MCS] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [MCS] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [MCS] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [MCS] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [MCS] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [MCS] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [MCS] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [MCS] SET  MULTI_USER 
GO
ALTER DATABASE [MCS] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [MCS] SET DB_CHAINING OFF 
GO
ALTER DATABASE [MCS] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [MCS] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
USE [MCS]
GO
/****** Object:  Table [dbo].[Config]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Config](
	[Name] [varchar](50) NOT NULL,
	[IntVal] [int] NULL,
	[StrVal] [varchar](50) NULL,
 CONSTRAINT [PK_Config] PRIMARY KEY CLUSTERED 
(
	[Name] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[ConfigTypeLane]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ConfigTypeLane](
	[TypeID] [tinyint] NOT NULL,
	[TypeName] [varchar](50) NOT NULL,
	[TypeDesc] [varchar](50) NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[DevStatus]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DevStatus](
	[ID] [int] NOT NULL,
	[Type] [nchar](10) NULL,
	[Status] [nchar](10) NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Foup]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Foup](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Location] [int] NOT NULL,
	[LocationType] [tinyint] NOT NULL,
	[Status] [tinyint] NOT NULL,
	[Lot] [int] NOT NULL,
	[BarCode] [int] NOT NULL,
	[Carrier] [int] NOT NULL,
	[Port] [int] NOT NULL,
 CONSTRAINT [PK_Foup] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[FoupDevice]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[FoupDevice](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[DevID] [int] NOT NULL,
	[DevType] [int] NOT NULL,
	[DevPortID] [int] NOT NULL,
	[DevPortKP] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[KeyPoints]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[KeyPoints](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Position] [int] NOT NULL,
	[Type] [int] NOT NULL,
	[SpeedRate] [tinyint] NULL,
	[TeachMode] [tinyint] NULL,
	[OHT_ID] [tinyint] NULL,
	[Lane_ID] [int] NULL,
	[Prev] [int] NULL,
	[Next] [int] NULL,
	[Name] [varchar](50) NULL,
	[refX] [float] NULL,
	[refY] [float] NULL,
PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Lane]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Lane](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[Start] [int] NOT NULL,
	[Finish] [int] NOT NULL,
	[Prev] [int] NOT NULL,
	[Next] [int] NOT NULL,
	[Next_Frok] [int] NOT NULL,
	[Length] [int] NOT NULL,
	[MapID] [int] NOT NULL,
	[Type] [tinyint] NOT NULL,
	[Enable] [bit] NOT NULL,
 CONSTRAINT [PK_PathInfo] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[LinkSession]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[LinkSession](
	[SessionID] [int] IDENTITY(1,1) NOT NULL,
	[UserID] [int] NOT NULL,
	[RealRight] [int] NOT NULL,
	[OrginRight] [int] NOT NULL,
	[AccessTime] [datetime] NOT NULL,
	[ConnectInfo] [varchar](200) NOT NULL,
	[UserStatus] [int] NOT NULL,
 CONSTRAINT [PK_LinkSession] PRIMARY KEY CLUSTERED 
(
	[SessionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[MapInfo]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MapInfo](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Descript] [ntext] NULL,
	[CreateTime] [datetime] NOT NULL,
 CONSTRAINT [PK_MapInfo] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[McsUser]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[McsUser](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](50) NOT NULL,
	[Password] [varchar](50) NOT NULL,
	[UserRight] [int] NOT NULL,
 CONSTRAINT [PK_McsUser] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[OHVLocal]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OHVLocal](
	[ID] [int] NULL,
	[PosFrom] [int] NULL,
	[PosTo] [int] NULL,
	[FoupID] [int] NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[OptsRights]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[OptsRights](
	[OPT] [varchar](50) NOT NULL,
	[MODE] [int] NOT NULL,
	[RoleRight] [int] NOT NULL,
 CONSTRAINT [PK_OptsRights] PRIMARY KEY CLUSTERED 
(
	[OPT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[RightInfo]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[RightInfo](
	[ID] [int] NOT NULL,
	[RoleName] [varchar](50) NOT NULL,
 CONSTRAINT [PK_RightInfo] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Stocker]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Stocker](
	[ID] [int] NULL,
	[Max] [int] NULL,
	[Free] [int] NULL,
	[Status] [nchar](10) NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[TransCommand]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TransCommand](
	[id] [int] NOT NULL,
	[Command] [nchar](10) NULL,
	[TransferID] [int] NOT NULL,
	[CmdType] [int] NOT NULL,
	[PosFrom] [int] NOT NULL,
	[PosTo] [int] NOT NULL,
	[FoupID] [int] NOT NULL,
	[Status] [int] NOT NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Transfer]    Script Date: 2013/1/22 11:48:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Transfer](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[FoupID] [int] NOT NULL,
	[Source] [int] NOT NULL,
	[Destination] [int] NOT NULL,
	[Status] [varchar](50) NOT NULL,
	[Priority] [int] NOT NULL,
 CONSTRAINT [PK_Transfer] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Config] ([Name], [IntVal], [StrVal]) VALUES (N'MapInUse', 1, NULL)
INSERT [dbo].[Config] ([Name], [IntVal], [StrVal]) VALUES (N'MapNameInUse', NULL, N'LoopTest')
INSERT [dbo].[ConfigTypeLane] ([TypeID], [TypeName], [TypeDesc]) VALUES (1, N'line', NULL)
INSERT [dbo].[ConfigTypeLane] ([TypeID], [TypeName], [TypeDesc]) VALUES (2, N'curve', NULL)
INSERT [dbo].[ConfigTypeLane] ([TypeID], [TypeName], [TypeDesc]) VALUES (3, N'fork', NULL)
SET IDENTITY_INSERT [dbo].[Foup] ON 

INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (46, -1, 1, 0, 0, 100, 239, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (47, -1, 1, 0, 0, 1000, 239, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (48, -1, 1, 0, 0, 1001, 239, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (49, -1, 1, 0, 0, 1002, 239, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (50, -1, 1, 0, 0, 10000, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (51, -1, 1, 0, 0, 10001, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (52, -1, 1, 0, 0, 10002, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (53, -1, 1, 0, 0, 10003, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (54, -1, 1, 0, 0, 11000, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (55, -1, 1, 0, 0, 12000, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (56, -1, 1, 0, 0, 12100, 100, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (57, -1, 1, 0, 0, 15000, 150, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (58, -1, 1, 0, 0, 20000, 239, 0)
INSERT [dbo].[Foup] ([ID], [Location], [LocationType], [Status], [Lot], [BarCode], [Carrier], [Port]) VALUES (59, -1, 1, 0, 0, 20010, 239, 0)
SET IDENTITY_INSERT [dbo].[Foup] OFF
SET IDENTITY_INSERT [dbo].[KeyPoints] ON 

INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (4, 0, 1, NULL, NULL, NULL, 1, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (5, 50, -1, NULL, NULL, NULL, 3, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (6, 450, -1, NULL, NULL, NULL, 5, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (7, 500, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (9, 600, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (10, 650, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (11, 1050, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (12, 1100, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (13, 1200, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[KeyPoints] ([Id], [Position], [Type], [SpeedRate], [TeachMode], [OHT_ID], [Lane_ID], [Prev], [Next], [Name], [refX], [refY]) VALUES (14, 1, 2, 12, 1, 100, 0, 0, 0, NULL, NULL, NULL)
SET IDENTITY_INSERT [dbo].[KeyPoints] OFF
SET IDENTITY_INSERT [dbo].[Lane] ON 

INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (1, 4, 5, -1, 3, -1, 50, 1, 2, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (3, 5, 6, 1, 5, -1, 400, 1, 1, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (5, 6, 7, 3, 6, -1, 50, 1, 2, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (6, 7, 9, 5, 7, -1, 100, 1, 1, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (7, 9, 10, 6, 8, -1, 50, 1, 2, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (8, 10, 11, 7, 12, -1, 400, 1, 1, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (12, 11, 12, 8, 13, -1, 50, 1, 2, 1)
INSERT [dbo].[Lane] ([id], [Start], [Finish], [Prev], [Next], [Next_Frok], [Length], [MapID], [Type], [Enable]) VALUES (13, 12, 13, 12, 1, -1, 100, 1, 1, 1)
SET IDENTITY_INSERT [dbo].[Lane] OFF
SET IDENTITY_INSERT [dbo].[LinkSession] ON 

INSERT [dbo].[LinkSession] ([SessionID], [UserID], [RealRight], [OrginRight], [AccessTime], [ConnectInfo], [UserStatus]) VALUES (1, 1, 4, 4, CAST(0x0000A12D00E21238 AS DateTime), N'local address = 127.0.0.1:21210

remote address = 127.0.0.1:43284', 1)
SET IDENTITY_INSERT [dbo].[LinkSession] OFF
SET IDENTITY_INSERT [dbo].[MapInfo] ON 

INSERT [dbo].[MapInfo] ([ID], [Name], [Descript], [CreateTime]) VALUES (1, N'Single Loop', N'test rail for local', CAST(0x0000A12B00DF9260 AS DateTime))
SET IDENTITY_INSERT [dbo].[MapInfo] OFF
SET IDENTITY_INSERT [dbo].[McsUser] ON 

INSERT [dbo].[McsUser] ([id], [Name], [Password], [UserRight]) VALUES (1, N'admin', N'ad53c70e673460a260d12cdfb59e43eb9a5b7f9b', 4)
SET IDENTITY_INSERT [dbo].[McsUser] OFF
INSERT [dbo].[OptsRights] ([OPT], [MODE], [RoleRight]) VALUES (N'OHT.POS', 0, 3)
INSERT [dbo].[OptsRights] ([OPT], [MODE], [RoleRight]) VALUES (N'OHT.STS', 0, 3)
INSERT [dbo].[OptsRights] ([OPT], [MODE], [RoleRight]) VALUES (N'STK.FOUP', 0, 3)
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (1, N'NoRight')
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (2, N'Viewer')
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (3, N'Guest')
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (4, N'Operator')
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (5, N'Builder')
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (6, N'Admin')
INSERT [dbo].[RightInfo] ([ID], [RoleName]) VALUES (7, N'SuperAdmin')
SET IDENTITY_INSERT [dbo].[Transfer] ON 

INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (5, 3003, -1, 1010, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (6, 3003, -1, 410, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (7, 20, -1, 120, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (8, 3100, -1, 120, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (9, 2001, -1, 410, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (10, 3003, -1, 120, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (11, 1100, -1, 410, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (12, 4700, -1, 410, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (13, 10000, -1, 1010, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (14, 10000, -1, 410, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (15, 100, -1, 120, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (16, 1000, -1, 120, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (17, 1000, -1, 410, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (18, 1000, -1, 1010, N'Finished', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (19, 10001, -1, 1010, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (20, 10001, -1, 410, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (21, 10001, -1, 120, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (22, 10002, -1, 1010, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (23, 10003, -1, 1010, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (24, 10003, -1, 410, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (25, 1001, -1, 1010, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (26, 1001, -1, 120, N'Prepare', 100)
INSERT [dbo].[Transfer] ([id], [FoupID], [Source], [Destination], [Status], [Priority]) VALUES (27, 15000, -1, 1010, N'Add', 100)
SET IDENTITY_INSERT [dbo].[Transfer] OFF
/****** Object:  Index [IX_BarCode]    Script Date: 2013/1/22 11:48:33 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_BarCode] ON [dbo].[Foup]
(
	[BarCode] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
SET ANSI_PADDING ON

GO
/****** Object:  Index [IX_Name]    Script Date: 2013/1/22 11:48:33 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_Name] ON [dbo].[McsUser]
(
	[Name] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
USE [master]
GO
ALTER DATABASE [MCS] SET  READ_WRITE 
GO
