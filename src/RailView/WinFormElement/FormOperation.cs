﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace WinFormElement
{
    public class FormOperation
    {
        FormShowRegion formShowRegion = new FormShowRegion();
        FormTreeViewOp formTreeViewOp = new FormTreeViewOp();
        //Map<Vehicle> vehicleList = new List<Vehicle>();
        Dictionary<uint, Vehicle> dictVechiles = new Dictionary<uint, Vehicle>();
        [DllImport("kernel32.dll")]
        private static extern int GetTickCount();

        public FormOperation()
        {
        }

        public void FormShowRegionInit()
        {
            if (formShowRegion.ReadRailSaveFile())
            {
                formShowRegion.InitRailList();
            }
        }

        public void ShowRegion(Graphics canvas)
        {
            //RemoveLencyOHT();
            formShowRegion.DrawRailInfo(canvas);
            formShowRegion.DrawVehicleInfo(canvas, dictVechiles);
        }

        public void RemoveLencyOHT()
        {
            int nNow = GetTickCount();
            foreach (KeyValuePair<uint, Vehicle> item in dictVechiles)
            {
                Vehicle oht = item.Value;
                if (nNow - oht.UpdateTime > 10000)
                {
                    dictVechiles.Remove(oht.ID);
                }
            }
        }

        public void UpdateOHTPos(List<OhtPos> listOhtPos)
        {
            foreach (OhtPos item in listOhtPos)
            {
                if (dictVechiles.ContainsKey(item.nID))
                {
                    Vehicle oht;
                    bool bGet = dictVechiles.TryGetValue(item.nID, out oht);
                    if (bGet)
                    {
                        oht.PosCode = item.nPos;
                        oht.Hand = item.nHand;
                        oht.UpdateTime = GetTickCount();
                    }
                }
                else
                {
                    Vehicle oht = new Vehicle(item.nID);
                    oht.PosCode = item.nPos;
                    oht.Hand = item.nHand;
                    oht.UpdateTime = GetTickCount();
                    dictVechiles.Add(item.nID, oht);
                }

               
            }


        }

        

        ////添加第二个参数，表示添加节点类型，根据节点类型调用switch函数
        //public void AddVehicleNode(TreeView tempTreeView)
        //{
        //    Vehicle vehicle = new Vehicle(vehicleID);
        //    vehicleList.Add(vehicle);
        //    formTreeViewOp.AddVehicleNode(tempTreeView, vehicleID);
        //    vehicleID++;
        //}

        public void DeleteVehicleNode(TreeView tempTreeView)
        { }
    }
}
