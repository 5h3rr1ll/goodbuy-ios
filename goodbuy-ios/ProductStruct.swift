//
//  ProductStruct.swift
//  goodbuy-ios
//
//  Created by Anthony Sherrill on 10.07.20.
//  Copyright © 2020 Anthony Sherrill. All rights reserved.
//

import Foundation

struct Product: Decodable {
    var id : Int
    var brand : String
    var corporation : String
    var barcode : String
    var name: String
    var is_big_ten: Bool
    var scanned_counter: Int
    var state: Int
    var upvote_counter: Int
    var downvote_counter: Int
}
